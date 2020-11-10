#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
using namespace std;
class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);
    Graph();
    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);
    void deleteEdge(int a,int b);
    void detachVertex(int v);
    vector<int> getNeighborsOf(int vertex);
    vector<vector<int>> getEdges() const;
    int numberOfVertices();
    // no need for a destructor and operator= because it will be saved on the stack
private:
    std::vector<std::vector<int>> edges;
};

#endif
