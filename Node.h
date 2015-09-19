using namespace std;
#include <D:\Study related\Programming\TAMU\AI_Search_Algorithms\variables.h>



typedef vector<array<int,4>> Vertex;
Vertex vertices; // useful variable to store all the vertices of the graph
typedef vector<array<int,3>> Edge;
Edge edges; //variable to store all the edges of the graph
int vertex_count; // number of vertex
int edge_count; // number of edges

class Node
{
public:
    int v;
    Node* parent;
    int depth;
    float heur;
    Node(int I)
    {
        v =I;
    }
    Node(int I, Node *p)
    {
        v = I;
        parent = p;
    }
    vector<Node*> successors();
    vector<Node*> traceback();
};

vector<Node*> nodeVector;

vector<Node*> Node::successors()
{
    vector<Node*> succ;
    for(Edge::iterator it = edges.begin(); it != edges.end(); it++)
    {
        if(v==(*it)[1])
        {
            succ.push_back(nodeVector[(*it)[2]]);
        }
        if(v==(*it)[2])
        {
            succ.push_back(nodeVector[(*it)[1]]);
        }
    }
    return succ;

}

vector<Node*> Node::traceback()
{
//    if(parent==NULL) return NULL;
    Node* currentNode = this;
    vector<Node*> pathToSource;
    if(parent==NULL) cout<<"WTF";
    if(parent==NULL) return pathToSource;
    cout<<"Path is "<<endl;
    while(currentNode->parent!=NULL)
    {
        pathToSource.push_back(currentNode);
        cout<<vertices[currentNode->v][1]<<" "<<vertices[currentNode->v][2]<<endl;
        currentNode = currentNode->parent;
    }
    pathToSource.push_back(currentNode);
    cout<<vertices[currentNode->v][1]<<" "<<vertices[currentNode->v][2]<<endl;
    return pathToSource;
}

