#include <queue>
#include <stack>

vector<Node*> Search_BFS(Node *initialState, Node* goalState);
vector<Node*> Search_DFS(Node *initialState, Node* goalState);
vector<Node*> Search_GBFS(Node *initialState, Node* goalState);
void addToSeen(Node* n);
bool seen(Node* n);

//For choosing betweeen BFS, DFS and GBFS
vector<Node*> Search(Node *initialState, Node* goalState, int typeOfSearch)
{
    if(typeOfSearch==0)
    {
       return Search_BFS(initialState, goalState);
    }
    else if(typeOfSearch==1)
        return Search_DFS(initialState, goalState);
    else if(typeOfSearch==2)
        return Search_GBFS(initialState, goalState);
    else { cout<<"not a valid search option"<<endl;  }
}

vector<Node*> Search_BFS(Node *initialState, Node* goalState)
{
    cout<<"Started BFS"<<endl;
    queue<Node*> frontier;
    frontier.push(initialState);
    Node* currentNode;
    vector<Node*> children;
    int total_iterations = 0, vertices_visited =0, path_length =0, max_frontier_size=0;

    //Sees which nodes are not yet explored or are not in the queue and proceeds accordingly
    while (!frontier.empty())
    {
        total_iterations+=1;
        (currentNode) = frontier.front();
        max_frontier_size = (frontier.size()>max_frontier_size) ? frontier.size() : max_frontier_size;
        frontier.pop();
        if(currentNode->v == goalState->v)
            {
                cout<<"Total iterations = "<<total_iterations<<endl<<"Vertices visited = "<<vertices_visited<<endl<<"Max Frontier size= "<<max_frontier_size<<endl;
                return currentNode->traceback();
            }
        addToSeen(currentNode);
        children = currentNode->successors();

        cout<<endl<<"Size of the frontiier is "<<frontier.size();
//        cout<<endl<<"list of the successors of currentNode is ";
        for(vector<Node*>::iterator it = children.begin(); it != children.end(); it++)
        {
//            cout<<(*it)->v<<" ";
            if(!seen(*it))
            {
                cout<<endl<<"Current Node is "<<currentNode->v<<" and unseen child is"<<(*it)->v<<endl;
                frontier.push(*it);
                addToSeen(*it);
                (*it)->parent = currentNode;
                vertices_visited+=1;
            }
//            else
//            {
//                cout<<"It was seen before"<<endl;
//            }
                //GBFS lafda
        }
    }
}

void addToSeen(Node* n)
{
//    cout<<"Enters addToSeen"<<" v value is "<<n->v<<endl;
    vertices[n->v][3] = 1;
//    cout<<"Not able to exit addToSeen"<<endl;
}

bool seen(Node *n)
{
    if(vertices[n->v][3]==1) return true;
    return false;
}

vector<Node*> Search_DFS(Node *initialState, Node* goalState)
{
    cout<<"Started DFS"<<endl;
    stack<Node*> frontier;
    frontier.push(initialState);
    Node* currentNode;
    vector<Node*> children;
    int total_iterations = 0, vertices_visited =0, path_length =0, max_frontier_size=0;

    while (!frontier.empty())
    {
        total_iterations+=1;
        (currentNode) = frontier.top();
        max_frontier_size = frontier.size()>max_frontier_size ? frontier.size() : max_frontier_size;
        frontier.pop();
        if(currentNode->v == goalState->v)
            {
                cout<<"Total iterations = "<<total_iterations<<endl<<"Vertices visited = "<<vertices_visited<<endl<<"Max Frontier size= "<<max_frontier_size<<endl;
                return currentNode->traceback();
            }
        addToSeen(currentNode);
        children = currentNode->successors();
//        cout<<"Size of the frontier is "<<frontier.size()<<endl;

        for(vector<Node*>::iterator it = children.begin(); it != children.end(); it++)
        {
            if(!seen(*it))
            {

                frontier.push(*it);

                addToSeen(*it);
                (*it)->parent = currentNode;
                vertices_visited+=1;
            }
//            else
//            {
//                cout<<"It was seen before"<<endl;
//            }
        }
    }


}

//To calculate the distance of current node from goalState
float calcHeur(Node* curr, Node* goalState)
{
    return sqrt(pow((vertices[goalState->v][1]-vertices[curr->v][1]), 2) +pow((vertices[goalState->v][2]-vertices[curr->v][2]), 2));
}

//So that priority queue can compare between nodes
class CompareDist
{
public:
    bool operator()(Node* n1, Node* n2)
    {
        if(n1->heur>n2->heur) return true;
        return false;
    }
};

vector<Node*> Search_GBFS(Node *initialState, Node* goalState)
{
    priority_queue <Node*, vector<Node*>, CompareDist> frontier;
    frontier.push(initialState);
    Node* currentNode;
    vector<Node*> children;
    int total_iterations = 0, vertices_visited =0, path_length =0, max_frontier_size=0;

    while (!frontier.empty())
    {
        total_iterations+=1;
        currentNode = frontier.top();
        max_frontier_size = frontier.size()>max_frontier_size ? frontier.size() : max_frontier_size;
        frontier.pop();
        if(currentNode->v == goalState->v)
            {
                cout<<"Total iterations = "<<total_iterations<<endl<<"Vertices visited = "<<vertices_visited<<endl<<"Max Frontier size= "<<max_frontier_size<<endl;
                return currentNode->traceback();
            }
        addToSeen(currentNode);
        children = currentNode->successors();
//        cout<<"Size of the frontier is "<<frontier.size()<<endl;

        for(vector<Node*>::iterator it = children.begin(); it != children.end(); it++)
        {
            if(!seen(*it))
            {


                addToSeen(*it);
                (*it)->heur = calcHeur((*it), goalState);
                (*it)->parent = currentNode;
                frontier.push(*it);
                vertices_visited+=1;
            }
//            else
//            {
//                cout<<"It was seen before"<<endl;
//            }
        }
    }
}

