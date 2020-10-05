#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph 
{ 
    int V; // No. of vertices 
    // Pointer to an array containing adjacency lists 
    list<int>* adj; 
public: 
    Graph(int); // Constructor 
    ~Graph();    // Destructor 
  
    // function to add an edge to graph 
    void addEdge(int, int); 
  
    // The function to do DFS traversal 
    void DFS(int, vector<bool> &, vector<int> &, int &); 
  
    // The function to do Topological Sort. 
    void topologicalSort(); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 

Graph::~Graph(){
    delete[] adj;
}

void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w);    // Add w to v's list. 
}

void Graph::DFS(int v, vector<bool> &visited,  
                vector<int> &departure, int &time) 
{
    visited[v] = true; 
    // time++;    // arrival time of vertex v 
  
    for(int i : adj[v]) 
        if(!visited[i]) 
            DFS(i, visited, departure, time); 
  
    // set departure time of vertex v 
    departure[++time] = v;
}

void Graph::topologicalSort() 
{
    vector<int> departure(V, -1);

    vector<bool> visited(V, false); 
    int time = -1;

    for(int i = 0; i < V; i++) 
        if(!visited[i]) 
            DFS(i, visited, departure, time);

    for(int i = V - 1; i >= 0; i--) 
        cout << departure[i] << " ";
}


int main(){
    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "Topological Sort of the given graph is \n"; 
    g.topologicalSort();
    cout<<endl;
    return 0;
}