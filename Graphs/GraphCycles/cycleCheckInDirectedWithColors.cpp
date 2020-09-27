#include <iostream>
#include <list>
using namespace std;
enum Color {WHITE, GRAY, BLACK};

class Graph{
    int V;
    list<int> *adj;
    bool isCyclicUtil(int node, int *color);
public:
    Graph(int V);
    void addEdge(int u, int v);
    bool isCyclic();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int> [V];
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

bool Graph::isCyclicUtil(int node, int *color){
    color[node] = GRAY;
    for(auto i:adj[node]){
        if(color[i]==GRAY){
            return true;
        }
        if(color[i]==WHITE && isCyclicUtil(i, color)){
            return true;
        }
    }
    color[node] = BLACK;
    return false;
}

bool Graph::isCyclic(){
    int *color = new int[V];

    for(int i=0;i<V;i++){
        color[i] = WHITE;
    }

    for(int i=0;i<V;i++){
        if(color[i]==WHITE)
        if(isCyclicUtil(i, color)){
            return true;
        }
    }
    return false;
}

int main(){
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    if (g.isCyclic()) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle";
    cout<<endl;
    return 0;
}