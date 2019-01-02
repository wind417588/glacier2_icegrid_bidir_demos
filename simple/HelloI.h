#ifndef __HELLOI_H__
#define __HELLOI_H__

#include "Hello.h"

using namespace std;

class HelloI : public Demo::Hello
{
public:
    virtual string SayHello(const string&, const Ice::Current&);
};

#endif
