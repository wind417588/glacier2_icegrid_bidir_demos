// **********************************************************************
//
// Copyright (c) 2003-2018 ZeroC, Inc. All rights reserved.
//
// **********************************************************************

#include <Ice/Ice.h>
#include <CallbackI.h>

using namespace std;
using namespace Ice;
using namespace Demo;

CallbackSenderI::CallbackSenderI() :
    _destroy(false)
{
}

void
CallbackSenderI::destroy()
{
    {
        IceUtil::Monitor<IceUtil::Mutex>::Lock lck(*this);

        cout << "destroying callback sender" << endl;
        _destroy = true;

        notify();
    }

    getThreadControl().join();
}

void
CallbackSenderI::addClient(const CallbackReceiverPrx& client, const Current& current)
{
	//new add
	//client->callback(0);
	//end
	
    IceUtil::Monitor<IceUtil::Mutex>::Lock lck(*this);
    cout << "adding client `" << Ice::identityToString(client->ice_getIdentity()) << "'"<< endl;
    cout << "adding client: " << current.adapter->getCommunicator()->proxyToString(client)  << endl;
    //_clients.insert(client->ice_fixed(current.con));
	_clients.insert(client);
}

void
CallbackSenderI::run()
{
    int num = 0;
    bool destroyed = false;
    while(!destroyed)
    {
        std::set<Demo::CallbackReceiverPrx> clients;
        {
            IceUtil::Monitor<IceUtil::Mutex>::Lock lck(*this);
            timedWait(IceUtil::Time::seconds(2));

            if(_destroy)
            {
                destroyed = true;
                continue;
            }

            clients = _clients;
        }

        if(!clients.empty())
        {
            ++num;
            for(set<CallbackReceiverPrx>::iterator p = clients.begin(); p != clients.end(); ++p)
            {
                try
                {
                    (*p)->callback(num);
					//cout << "#############removing client: " << (*p)->ice_toString() << endl;
                }
                catch(const Exception& ex)
                {
                    cerr << "removing client `" << Ice::identityToString((*p)->ice_getIdentity()) << "':\n"
                         << ex << endl;
					cerr << "removing client: " << (*p)->ice_toString() << endl;

                    IceUtil::Monitor<IceUtil::Mutex>::Lock lck(*this);
                    _clients.erase(*p);
                }
            }
        }
    }
}
