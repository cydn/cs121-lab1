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
        number = val;
        is_visited = false;
    };

    int number;
    bool is_visited;
    int distance = 0;

    list<Vertex> neighbours;
    void visit(int dis);
};
