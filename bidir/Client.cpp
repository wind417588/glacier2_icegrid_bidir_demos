// **********************************************************************
//
// Copyright (c) 2003-2018 ZeroC, Inc. All rights reserved.
//
// **********************************************************************

#include <Ice/Ice.h>
#include <Callback.h>

using namespace std;
using namespace Demo;


Ice::CommunicatorPtr communicator;

//
// Callback for CtrlCHandler
//
void destroyCommunicator(int)
{   
    communicator->destroy();
}

class CallbackReceiverI : public CallbackReceiver
{
public:
    
    virtual void callback(Ice::Int num, const Ice::Current&)
    {   
        cout << "received callback #" << num << endl;
    }
};


int run(const Ice::CommunicatorPtr&);

int main(int argc, char* argv[])
{
#ifdef ICE_STATIC_LIBS
    Ice::registerIceSSL();
    Ice::registerIceUDP();
    Ice::registerIceWS();
#endif

    int status = 0;

    try
    {
		Ice::CtrlCHandler ctrlCHandler;
        //
        // CommunicatorHolder's ctor initializes an Ice communicator,
        // and its dtor destroys this communicator.
        //
        Ice::CommunicatorHolder ich(argc, argv, "config.client");
		communicator = ich.communicator();
		
		// Destroy communicator on Ctrl-C
		ctrlCHandler.setCallback(&destroyCommunicator);

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
            status = run(communicator);
        }
    }
    catch(const std::exception& ex)
    {
        cerr << argv[0] << ": " << ex.what() << endl;
        status = 1;
    }

    return status;
}

int run(const Ice::CommunicatorPtr& communicator)
{
    try
    {
		CallbackSenderPrx server = CallbackSenderPrx::checkedCast(communicator->stringToProxy("hello"));
        if(!server)
        {
            cerr << "invalid proxy" << endl;
            return 1;
        }

        //
        // Create an object adapter with no name and no endpoints for receiving callbacks
        // over bidirectional connections.
        //
        Ice::ObjectAdapterPtr adapter = communicator->createObjectAdapter("");

        //
        // Register the callback receiver servant with the object adapter and activate
        // the adapter.
        //
        CallbackReceiverPrx proxy = CallbackReceiverPrx::uncheckedCast(adapter->addWithUUID(new CallbackReceiverI));
        adapter->activate();

        //
        // Associate the object adapter with the bidirectional connection.
        //
        server->ice_getConnection()->setAdapter(adapter);

        //
        // Provide the proxy of the callback receiver object to the server and wait for
        // shutdown.
        //
        server->addClient(proxy);
        communicator->waitForShutdown();

    }
    catch (const Ice::Exception& ex)
    {
        cerr << ex << endl;
    }
	
    return 0;
}
