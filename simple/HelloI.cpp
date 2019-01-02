#include <Ice/Ice.h>
#include "HelloI.h"

using namespace std;

string HelloI::SayHello(const string& s, const Ice::Current&)
{
    string wholestr;
    cout << "server receive msg: " << s << endl;
    wholestr = "hello " + s;
    cout << "server return msg: " << wholestr << endl;
    return wholestr;
}
