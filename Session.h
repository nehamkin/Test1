#ifndef SESSION_H_
#define SESSION_H_
#include <vector>
#include <string>
#include "Graph.h"

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

private:
    Graph g;
    TreeType treeType;
    std::vector<Agent*> agents;
    int cycleNum;
};

#endif
