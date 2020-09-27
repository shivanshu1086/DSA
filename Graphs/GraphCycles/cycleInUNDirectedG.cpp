#include <iostream>
#include <list>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    bool isCyclicUtil(int node, bool *visited, int parent);
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
    adj[v].push_back(u);
}

bool Graph::isCyclicUtil(int node, bool *visited, int parent){
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i]){
            if (isCyclicUtil(i, visited, node))
              return true;
        }
        else if(i!=parent){
            return true;
        }
    }
    return false;
}

bool Graph::isCyclic(){
    bool *visited = new bool[V];

    for(int i=0;i<V;i++){
        visited[i] = false;
    }

    for(int i=0;i<V;i++){
        if(!visited[i])
        if(isCyclicUtil(i, visited, -1)){
            return true;
        }
    }
    return false;
}

int main(){
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.isCyclic()? cout << "Graph contains cycle\n": 
                   cout << "Graph doesn't contain cycle\n"; 
  
    Graph g2(3); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.isCyclic()? cout << "Graph contains cycle\n": 
                   cout << "Graph doesn't contain cycle\n";
    cout<<endl;
    return 0;
}