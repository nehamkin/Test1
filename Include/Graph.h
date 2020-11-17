#ifndef GRAPH_H_
#define GRAPH_H_
#include "Tree.h"
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
    vector<vector<int>> connectedComponents();
    void DFS(int v , vector<bool> *visited, vector<int> *component);
    vector<int> getNeighborsOf(int vertex);
    vector<vector<int>> getEdges() const;
    int numberOfVertices();

private:
    std::vector<std::vector<int>> edges;
};

#endif
