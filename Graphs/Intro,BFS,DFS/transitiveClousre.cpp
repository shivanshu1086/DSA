#include <iostream>
#include <list>
using namespace std;

class Graph{
    int V;
    bool **tc;
    list<int> *adj;
    void DFSUtil(int u, int v);
public:
    Graph(int V);
    void addEdge(int u, int v);
    void transitiveClousre();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int> [V];
    tc = new bool* [V];

    for(int i=0;i<V;i++){
        tc[i] = new bool[V];
        memset(tc[i], false, V*sizeof(bool));
    }
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

void Graph::DFSUtil(int u, int v){
    tc[u][v] = true;
    for(auto itr=adj[v].begin();itr!=adj[v].end();itr++){
        if(!tc[u][*itr]){
            DFSUtil(u,*itr);
        }
    }
}

void Graph::transitiveClousre(){
    for(int i=0;i<V;i++){
        DFSUtil(i,i);
    }

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<tc[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    Graph g(4);
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3);

    cout << "Transitive closure matrix is \n"; 
    g.transitiveClousre();
    cout<<endl;
	return 0;
}