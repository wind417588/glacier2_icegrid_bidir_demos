// **********************************************************************
//
// Copyright (c) 2003-2018 ZeroC, Inc. All rights reserved.
//
// **********************************************************************

#include <Ice/Ice.h>
#include <HelloI.h>

using namespace std;

//
// Global variable for shutdownCommunicator
//
Ice::CommunicatorPtr communicator;

//
// Callback for CtrlCHandler
//
void
shutdownCommunicator(int)
{
    communicator->shutdown();
}

int
main(int argc, char* argv[])
{
#ifdef ICE_STATIC_LIBS
    Ice::registerIceSSL();
    Ice::registerIceUDP();
    Ice::registerIceWS();
#endif
    int status = 0;

    try
    {
        //
        // CtrlCHandler must be created before the communicator or any other threads are started
        //
        Ice::CtrlCHandler ctrlCHandler;

        //
        // CommunicatorHolder's ctor initializes an Ice communicator,
        // and it's dtor destroys this communicator.
        //
        Ice::CommunicatorHolder ich(argc, argv, "config.server");
        communicator = ich.communicator();

        //
        // Shutdown communicator on Ctrl-C
        //
        ctrlCHandler.setCallback(&shutdownCommunicator);

        //
        // The communicator initialization removes all Ice-related arguments from argc/argv
        //
        if(argc > 1)
        {
            cerr << argv[0] << ": too many arguments" << endl;
            status = 1;
        }
        else
        {
            Ice::ObjectAdapterPtr adapter = communicator->createObjectAdapter("Hello");
            Demo::HelloPtr hello = new HelloI;
            adapter->add(hello, Ice::stringToIdentity("hello"));
            adapter->activate();

            communicator->waitForShutdown();
        }
    }
    catch(const std::exception& ex)
    {
        cerr << ex.what() << endl;
        status = 1;
    }

    return status;
}
