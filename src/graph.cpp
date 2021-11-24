#include "graph.hpp"
/**
 * @brief To check if the vertex is visited
 * 
 */
void Vertex::visit(int dis){
    if (!is_visited)
    {
        is_visited = true;
        distance = dis;
    }else return;
}