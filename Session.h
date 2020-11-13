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
    Session(const std::string& path);
    virtual ~Session();
    Session(const Session &other);
    Session& operator=(const Session &other);
    Session(Session && other);
    Session& operator=(Session &&other);
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
