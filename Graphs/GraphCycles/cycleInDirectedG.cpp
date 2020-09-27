#include <iostream>
#include <list>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    bool isCyclicUtil(int node, bool *visited, bool *recStack);
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

bool Graph::isCyclicUtil(int node, bool *visited, bool *recStack){
    if(!visited[node]){
        visited[node] = true; 
        recStack[node] = true;

        for(auto i:adj[node]){
            if(!visited[i] && isCyclicUtil(i,visited,recStack)){
                return true;
            }
            else if(recStack[i]){
                return true;
            }
        }
    }

    recStack[node] = false;
    return false;
}

bool Graph::isCyclic(){
    bool *visited = new bool[V];
    bool *recStack = new bool[V];

    for(int i=0;i<V;i++){
        visited[i] = false;
        recStack[i] = false;
    }

    for(int i=0;i<V;i++){
        if(isCyclicUtil(i, visited, recStack)){
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
  
    if(g.isCyclic()) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle";
    cout<<endl;
    return 0;
}