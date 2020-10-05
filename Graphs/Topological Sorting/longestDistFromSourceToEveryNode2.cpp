#include <iostream>
#include <list>
#include <stack>
using namespace std;

class AdjListNode{
    int v;
    int weight;
public:
    AdjListNode(int _v, int _w){
        v = _v;
        weight = _w;
    }
    int get_v(){return v;}
    int get_weight(){return weight;}
};

class Graph{
    int V;
    list<AdjListNode> *adj;
    void topologicalSortUtil(int v, bool *visited, stack<int> &Stack);
public:
    Graph(int v);
    ~Graph();
    void addEdge(int u, int v, int weight);
    void longestPath(int v);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<AdjListNode>[V];
}

Graph::~Graph(){
    delete[] adj;
}

void Graph::addEdge(int u, int v, int weight){
    AdjListNode node(v,weight);
    adj[u].push_back(node);
}

void Graph::topologicalSortUtil(int v, bool *visited, stack<int> &Stack){
    visited[v] = true;

    list<AdjListNode>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++){
        AdjListNode node = *i;
        if(!visited[node.get_v()]){
            topologicalSortUtil(node.get_v(),visited,Stack);
        }
    }

    Stack.push(v);
}

void Graph::longestPath(int v){
    bool *visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
    }

    stack<int> Stack;

    for(int i=0;i<V;i++){
        if(!visited[i]){
            topologicalSortUtil(i,visited,Stack);
        }
    }

    int *dist = new int[V];
    for(int i=0;i<V;i++){
        dist[i] = INT_MAX;
    }

    dist[v] = 0;

    while(!Stack.empty()){
        int u = Stack.top();
        Stack.pop();

        if(dist[u]!=INT_MAX){
            for(AdjListNode i:adj[u]){
                if(dist[i.get_v()]>dist[u]+i.get_weight()*-1){
                    dist[i.get_v()] = dist[u] + i.get_weight() * -1;
                }
            }
        }
    }

    for (int i = 0; i < V; i++) 
    { 
        if (dist[i] == INT_MAX) 
            cout << "INT_MIN "; 
        else
            cout << (dist[i] * -1) << " "; 
    }

    delete[] visited;
    delete[] dist;
}

int main(){
    Graph g(6); 
  
    g.addEdge(0, 1, 5); 
    g.addEdge(0, 2, 3); 
    g.addEdge(1, 3, 6); 
    g.addEdge(1, 2, 2); 
    g.addEdge(2, 4, 4); 
    g.addEdge(2, 5, 2); 
    g.addEdge(2, 3, 7); 
    g.addEdge(3, 5, 1); 
    g.addEdge(3, 4, -1); 
    g.addEdge(4, 5, -2); 
  
    int s = 1; 
  
    cout << "Following are longest distances from "
         << "source vertex " << s << " \n"; 
    g.longestPath(s);
    cout<<endl;
    return 0;
}