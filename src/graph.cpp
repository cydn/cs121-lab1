#include "graph.hpp"

/**
 * @brief Construct a new undirect Graph::undirect Graph object
 * 
 * @param path 
 */
undirect_Graph::undirect_Graph(string path)
{
    ifstream data(path);
    int dat;
    data >> dat;
    cout << "the count of Vertex : " << dat << " ";
    m_countOfVertex =dat;
    data >> dat;
    cout << "the count of Edge : " << dat << " ";
    m_countOfEdge = dat;
    cout << endl;
    neighbourVertexs = vector<Vertex *>(m_countOfVertex);
    for(int index = 0; index < m_countOfEdge; index++)
    {
        cout << "读取顶点： " ;
        data >> dat;
        cout << dat << "   ";
        int firstVertex = dat;
        
        cout << "读取顶点： " ;
        data >> dat;
        cout << dat << endl;
        
        int secondVertex = dat;
        addEdge(firstVertex, secondVertex);
        
    }
    
}

/**
 * @brief Used to add a vertex to another to construct a graph
 * 
 * @param firstVertex 
 * @param secondVertex 
 */
void undirect_Graph::addEdge(int firstVertex, int secondVertex)
{
    
    Vertex *firstVertexNode = new Vertex(firstVertex);
    Vertex *secondVertexNode = new Vertex(secondVertex);
    
    firstVertexNode->neighbours.push_back(secondVertexNode);
    firstVertexNode->in_out++;
    secondVertexNode->neighbours.push_back(firstVertexNode);
    secondVertexNode->in_out++;
    
    pair<int, Vertex*> v(firstVertex, firstVertexNode);
    pair<int, Vertex*> w(secondVertex, secondVertexNode);
    if (!isInserted(firstVertex, VertexSet))
    {
        VertexSet.insert(v);
    }
    else
    {
        VertexSet[firstVertex]->neighbours.push_back(secondVertexNode);
        
    }
    if(!isInserted(secondVertex, VertexSet))
    {
        VertexSet.insert(w);
    }
    else
    {
        VertexSet[secondVertex]->neighbours.push_back(firstVertexNode);
    }
}

/**
 * @brief To check if the node is inserted to the graph
 * 
 * @param v 
 * @param VertexSet 
 * @return true 
 * @return false 
 */
bool undirect_Graph::isInserted(int v, map<int, Vertex *> VertexSet)
{
    map<int, Vertex*>::iterator iter = VertexSet.begin();
    for(iter; iter != VertexSet.end(); iter++)
    {
        if(iter->first == v)
            return true;
    }
    return false;
}

/**
 * @brief Print
 * 
 */
void undirect_Graph::print_allVertexAndEdge()
{
    map<int, Vertex*>::iterator iter = VertexSet.begin();
    for(iter; iter != VertexSet.end(); iter++)
    {
        cout << "顶点" << iter->first << "的邻节点：";
        for(list<Vertex*>::iterator j = iter->second->neighbours.begin(); j != iter->second->neighbours.end(); j++)
        {
            cout << (*j)->number << " ";
        }
        cout << endl;
    }
}

/**
 * @brief 
 * 
 * @return map<int, Vertex*> 
 */
map<int, Vertex*> undirect_Graph::getGraphVertexSet()
{
    return VertexSet;
}

/**
 * @brief Return the number of vertex
 * 
 * @return int 
 */
int undirect_Graph::countOfVertex()
{
    return m_countOfVertex;
}

/**
 * @brief return the neighbour of the vertex
 * 
 * @return vector<Vertex*> 
 */
vector<Vertex*> undirect_Graph::get_neighbourVertexs()
{
    return neighbourVertexs;
}

/**
 * @brief To check if the vertex is visited
 * 
 */
void Vertex::visit(){
    is_visited = true;
}