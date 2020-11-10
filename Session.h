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
    void simulate();
    void addAgent(const Agent& agent);
    void setGraph(const Graph& graph);
    void enqueueInfected(int);
    int dequeueInfected();

    TreeType getTreeType() const;
    void printGraph();
    void printAgents();
    void printType();
    Graph getGraph()const;
    int getCycle() const;
    vector<bool> getRed() const;
    vector<bool> getYellow() const;
    int getAgentCounter() const;
    int getAgentSize() const;
    void setRed(int toChange);
    void setYellow(int toChange);
private:
    Graph g;
    TreeType treeType;
    std::vector<Agent*> agents;
    int cycleNum;
    vector<bool> red; // sick vertices
    vector<bool> yellow; //infected vertices
    int agentCounter; // counts how many agents acted
    int agentSize;// how many agents need to act
    queue<int> infectedQ;



};

#endif
