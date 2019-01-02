#include <Ice/Ice.h>
#include "HelloI.h"

using namespace std;

string HelloI::SayHello(const string& s, const Ice::Current&)
{
    string retStr;
	
    cout << "server recv msg: " << s << endl;
    retStr = "hello " + s;
    cout << "server send msg: " << retStr << endl;
    return retStr;
}
