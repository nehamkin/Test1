//
// Created by spl211 on 06/11/2020.
//

#include "Graph.h"

Graph::Graph(std::vector<std::vector<int>> matrix): edges(matrix) {}
Graph::Graph(): edges() {}
vector<vector<int>> Graph::getEdges() const {return edges;}
int Graph::numberOfVertices() {return edges.size();}
void Graph::deleteEdge(int a, int b) {
    edges[a][b]=edges[b][a]=0;
}