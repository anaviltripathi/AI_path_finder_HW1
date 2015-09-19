#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <array>
#include <D:\Study related\Programming\TAMU\AI_Search_Algorithms\Node.h>
#include <D:\Study related\Programming\TAMU\AI_Search_Algorithms\search_func.h>

using namespace std;


//vector<Node*> nodeVector;

int main()
{
    //Read the file into two vectors
    string line; //to take one line
    string vertices_line; //dummy variable to throw away "vertex:" written in the file
    string edges_line; //similar dummy variable to above for edges

    //Reading the file and storing the vertices and edges into vertices and edges
    ifstream ATM ("ATM.graph");

    if(ATM.is_open())
    {
        cout<<"Can read file  "<<endl;
        istringstream iss;
        int i = 0;
        while(getline(ATM, line))
        {
            if(i==0) //To get the vertex count from first line
            {
                stringstream linestream(line);
                getline(linestream, vertices_line, ' ');
                linestream >> vertex_count;
                i++;
                cout<<"Vertex count "<<vertex_count<<endl;
            }
            else
            {
                if(i<vertex_count+1)
                {
                    stringstream linestream(line);
//                    cout<<i<<endl<<linestream;
                    array<int,4> a = {0, 0, 0, 0};
                    linestream >> a[0] >> a[1]>> a[2];
                    vertices.push_back(a);
                    i++;
//                    cout<<i<<endl;
                }
                else
                {
                    if(i==vertex_count+1) //To get the edge count after vertex list has finished
                    {
                        stringstream linestream(line);
                        getline(linestream, edges_line, ' ');
                        linestream >>  edge_count;
                        cout<<"Edge count "<<edge_count<<endl;
                        i++;
                    }
                    else
                    {
                        stringstream linestream(line);
                        array<int,3> a = {0, 0, 0};
                        linestream >> a[0] >> a[1]>> a[2];
                        edges.push_back(a);
                        i++;
                    }
                }
            }

        }

        //Creating a vector of nodes from vertices
        for(Vertex::iterator it = vertices.begin(); it!= vertices.end(); it++)
        {
           nodeVector.push_back(new Node((*it)[0]));

        }

        cout<<"Size of the nodeVector is "<<nodeVector.size()<<endl;
        cout<<"Size of the edges is "<<edges.size()<<endl;

        //Taking the initial and goal states
        int x1, x2, y1, y2, typeOfSearch;
        Node* initialState;
        Node* goalState;
        cout<<"Enter the initial state coordinates ";
        cin>>x1>>y1;
        cout<<"Enter the goal state coordinates ";
        cin>>x2>>y2;
        cout<<"Enter 0 for BFS, 1 for DFS and 2 for GBFS ";
        cin>>typeOfSearch;

        int flag1=0, flag2=0;
        i=0;

//        for(Vertex::iterator it = vertices.begin(); it != vertices.end(); it++)
//        {
//            cout<<(*it)[0]<<" "<<(*it)[1]<<" "<<(*it)[2]<<" "<<(*it)[3]<<endl;
//        }

        for(Vertex::iterator it = vertices.begin(); it != vertices.end(); it++)
        {

            if((*it)[1]==x1 && (*it)[2]==y1)
            {
                initialState = nodeVector[i];
                initialState->parent=NULL;
                cout<<"Initial State is "<<initialState->v<<endl;
                flag1=1;
            }
            if((*it)[1]==x2 && (*it)[2]==y2)
            {
                goalState = nodeVector[i];
                cout<<"Goal State is "<<goalState->v<<endl;
                flag2=1;
            }
            if(flag1==1 and flag2==1) break;
            i++;
        }


        Search(initialState, goalState, typeOfSearch);
//        print()




    }

//    for(int i = 0; i<vertices.size(); ++i)
//    {
//        cout<<vertices[i][0]<<" "<<vertices[i][1]<<" "<<vertices[i][2]<<endl;
//    }
//    cout<<"NOw edges"<<endl;
//
//    for(int i = 0; i<edges.size(); ++i)
//    {
//        cout<<edges[i][0]<<" "<<edges[i][1]<<" "<<edges[i][2]<<endl;
//
//    }

}

