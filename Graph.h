#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);
    Graph();
    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);
    // no need for a destructor and operator= because it will be saved on the stack
private:
    std::vector<std::vector<int>> edges;
};

#endif
