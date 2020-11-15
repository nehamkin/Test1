#ifndef AGENT_H_
#define AGENT_H_

#include <vector>
#include "Session.h"

class Agent{
public:
    Agent();
    Agent(const Agent &agent); // copy constructor
    virtual Agent* clone() const=0;
    virtual void act(Session& session)=0;
    virtual string mytype();
//    virtual void print();
};

class ContactTracer: public Agent{
public:
    ContactTracer();
    string mytype();
    virtual Agent* clone() const;
    virtual void act(Session& session);
//    virtual void print();
};


class Virus: public Agent{
public:
    Virus(int nodeInd);
    string mytype();
    virtual Agent* clone() const;
    virtual void act(Session& session);
//    virtual void print();
private:
    const int nodeInd;
};

#endif
