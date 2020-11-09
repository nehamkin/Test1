#ifndef AGENT_H_
#define AGENT_H_

#include <vector>
#include "Session.h"

class Agent{
public:
    Agent();
//    virtual Agent* clone()=0;
    virtual void act(Session& session)=0;
      virtual string mytype();
};

class ContactTracer: public Agent{
public:
    ContactTracer();
    string mytype();
    virtual void act(Session& session);
};


class Virus: public Agent{
public:
    Virus(int nodeInd);
    string mytype();
    virtual void act(Session& session);
private:
    const int nodeInd;
};

#endif
