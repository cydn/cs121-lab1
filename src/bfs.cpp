#include "bfs.hpp"

void bfs_sequential(Vertex* root)
{
    int dis = 0;

    if (!root) return;
    queue<Vertex*> q;
    root->visit(0);
    q.push(root);
    
    while (!q.empty())
    {
        Vertex* node = q.front();
        node->visit(dis);
        q.pop();
        dis++;
        for(auto& i:root->neighbours){
            if (!i.is_visited)
            {
                i.visit(dis);
                q.push(&i);
            }
        }
    }
}