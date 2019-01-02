// **********************************************************************
//
// Copyright (c) 2003-2018 ZeroC, Inc. All rights reserved.
//
// **********************************************************************

#include <Ice/Ice.h>
#include <Glacier2/Glacier2.h>
#include <Hello.h>

using namespace std;
using namespace Demo;

class ChatClient : public Glacier2::Application
{
public:

    ChatClient() :

	// Since this is an interactive demo we don't want any signal handling.
    Glacier2::Application(Ice::NoSignalHandling)
    {
    }

    virtual Glacier2::SessionPrx createSession()
    {
        Glacier2::SessionPrx sess;
		//Glacier2::RouterPrx _router;
	
		_router = router();		
        while(!sess)
        {
            try
            {
				//sess = router()->createSession("", "");
				sess = _router->createSession("", "");
                break;
            }
            catch(const Glacier2::PermissionDeniedException& ex)
            {
                cout << "permission denied:\n" << ex.reason << endl;
            }
            catch(const Glacier2::CannotCreateSessionException& ex)
            {
                cout << "cannot create session:\n" << ex.reason << endl;
            }
        }
		
        return sess;
    }

	virtual int runWithSession(int argc, char *argv[])
    {
		int status = 0;
		do
		{
			if(argc > 1)
	        {
	            cerr << appName() << ": too many arguments" << endl;
				status = 1;
	            break;
	        }

			HelloPrx hello;
		    try
		    {
		        hello = HelloPrx::checkedCast(communicator()->stringToProxy("hello"));
		    }
		    catch (const Ice::Exception& ex)
		    {
		        cerr << ex << endl;
		    }

		    if (hello)
		    {
		        string ret = "";
				cout << "it will send a \"wind\" to the server." << endl;
		        ret = hello->SayHello("wind");
		        cout << "recv msg from server: " << ret << endl;
		    }
			else
			{
				cout << "couldn't find a hello object." << endl;
				status = 1;
			}
		}while(0);
		
        return status;
    }

    virtual void sessionDestroyed()
    {
        cout << "Connection lost." << endl;
    }

    protected:

  	Glacier2::RouterPrx _router;
};

int
main(int argc, char* argv[])
{
#ifdef ICE_STATIC_LIBS
    Ice::registerIceSSL();
#endif
    ChatClient app;
    return app.main(argc, argv, "config.client");
}
