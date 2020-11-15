#ifndef SESSION_H_
#define SESSION_H_
#include <vector>
#include <string>
#include "Graph.h"
#include <queue>
#include <fstream>
#include <iostream>
#include "json.hpp"
using json=nlohmann::json;

using namespace std;

class Agent;

enum TreeType{
  Cycle,
  MaxRank,
  Root
};

class Session{
public:
    Session(const std::string& path);           //constructor
//    -------RULE OF 5 -------------------------------------------
    virtual ~Session();                         //destructor
    Session(const Session &other);              //copy constructor
    Session& operator=(const Session &other);   //copy assignment
    Session(Session && other);                  //move constructor
    Session& operator=(Session &&other);        //move assignment
//    ------SIMULATE AND UNDER
    void simulate();
    bool condition();
    void addAgent(const Agent& agent);
    void setGraph(const Graph& graph);
    void enqueueInfected(int);
    int dequeueInfected();
    void detachVertex(int v);
    TreeType getTreeType() const;
    void printGraph();
    void printAgents();
    void printType();
    Graph getGraph()const;
    int getCycle() const;
    bool isRed(int x) const;
    bool isYellow(int x) const;
    int getAgentSize() const;
    void setRed(int toChange);
    void setYellow(int toChange);
    bool isInfectedQempty();
    void clear();
    vector<int> getInfected();
    void output();

private:
    Graph g;
    TreeType treeType;
    std::vector<Agent*> agents;
    int cycleNum;
    vector<bool> red; // sick vertices
    vector<bool> yellow; //infected vertices
//    int agentCounter; // counts how many agents acted
    int agentSize;// how many agents need to act
    queue<int> infectedQ;
};

#endif
