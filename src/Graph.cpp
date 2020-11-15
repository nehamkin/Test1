//
// Created by spl211 on 06/11/2020.
//

#include "Include/Graph.h"
#include <queue>

Graph::Graph(std::vector<std::vector<int>> matrix): edges(matrix) {}
Graph::Graph(): edges() {}
vector<vector<int>> Graph::getEdges() const {return edges;}
int Graph::numberOfVertices() {return edges.size();}
void Graph::deleteEdge(int a, int b) {
    edges[a][b]=edges[b][a]=0;
}
vector<int> Graph::getNeighborsOf(int vertex) {
    vector<int> neighbors;
    for(int i=0;i<edges.size();i++){
        if(edges[vertex][i]==1)
            neighbors.push_back(i);
    }
    return neighbors;
}
void Graph::detachVertex(int v) {
    for(int i=0; i<edges.size(); i++){
        deleteEdge(v,i);
    }
}

void Graph::DFS(int v, vector<bool> *visited,vector<int> *component) { //the v
    (*visited)[v]=true;
    (*component).push_back(v);
    for(int i=0; i<numberOfVertices();i++){
        if(edges[v][i]==1 && !(*visited)[i])
            DFS(i,visited,component);
    }
}

vector<vector<int>> Graph::connectedComponents() {
    vector<bool> visited;
    vector<vector<int>> output;
    for(int i=0; i<numberOfVertices();i++)
        visited.push_back(false);
    for(int i=0; i<numberOfVertices();i++){
        vector<int>* component;
        if(!visited[i])
        {
            vector<int> component;
            DFS(i,&visited,&component);
            output.push_back(component);
        }
    }
    return output;
}