// **********************************************************************
//
// Copyright (c) 2003-2018 ZeroC, Inc. All rights reserved.
//
// **********************************************************************

#include <Ice/Ice.h>
#include <Glacier2/Glacier2.h>
#include <Callback.h>

using namespace std;
using namespace Ice;
using namespace Demo;

class CallbackReceiverI : public CallbackReceiver
{
public:
    
    virtual void callback(Ice::Int num, const Ice::Current&)
    {   
        cout << "received callback #" << num << endl;
    }
};


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

		_router = router();
        while(!sess)
        {
            try
            {
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

		    try
		    {
				CallbackSenderPrx server = CallbackSenderPrx::checkedCast(communicator()->stringToProxy("hello"));
				if(!server)
				{
					cerr << "invalid proxy" << endl;
					status = 1;
	            	break;
				}
				
				//
				// Create an object adapter with no name and no endpoints for receiving callbacks
				// over bidirectional connections.
				//
				communicator()->setDefaultRouter(_router);
				Ice::ObjectAdapterPtr adapter = communicator()->createObjectAdapterWithRouter("CallbackReceiverAdapter", _router);

				string category = _router->getCategoryForClient();
		        Identity ident;
		        ident.name = "callbackReceiver";
		        ident.category = category;
				
				//
				// Register the callback receiver servant with the object adapter and activate
				// the adapter.
				//
				CallbackReceiverPrx proxy = CallbackReceiverPrx::uncheckedCast(adapter->add(new CallbackReceiverI, ident));
				adapter->activate();

				//
				// Associate the object adapter with the bidirectional connection.
				//
				//server->ice_getConnection()->setAdapter(adapter);
		
				//
				// Provide the proxy of the callback receiver object to the server and wait for
				// shutdown.
				//

				server->addClient(proxy);
				//communicator()->waitForShutdown();
		    }
			
		    catch (const Ice::Exception& ex)
		    {
		        cerr << ex << endl;
				status = 1;
				break;
		    }
		}while(0);

		getchar();
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
