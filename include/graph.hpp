#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <list>

#endif

using namespace std;

class Vertex
{
public:
    Vertex(int val)
    {
        in_out = 0;
        number = val;
    };
    int number;
    int in_out;
    list<Vertex *> neighbours;
    void visit();
private:
    bool is_visited = false;
};

class undirect_Graph
{
public:
    undirect_Graph(string path);
    int countOfVertex();  
    int countOfEdge();  
    void addEdge(int firstVertex, int secondVertex);
    void print_allVertexAndEdge();
    vector<Vertex*> get_neighbourVertexs();
    map<int, Vertex*> getGraphVertexSet();
private:
    int m_countOfVertex;
    int m_countOfEdge;
    map<int, Vertex *> VertexSet;
    bool isInserted(int v, map<int, Vertex*> VertexSet);
    vector<Vertex *> neighbourVertexs;
};
