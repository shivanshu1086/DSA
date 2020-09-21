#include <iostream>
#include <list>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int V);

    void addEdge(int v, int w);

    void BFS(int source);
};

Graph::Graph(int V){
    this->V=V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

void Graph::BFS(int source){
    bool *visited = new bool[V];

    for(int i = 0; i < V; i++) 
        visited[i] = false;
    
    list<int> queue;

    visited[source] = true; 
    queue.push_back(source);

    list<int>::iterator i;

    while(!queue.empty()){
        source = queue.front(); 
        cout << source << " "; 
        queue.pop_front();

        for(i=adj[source].begin();i!=adj[source].end();i++){
            if(!visited[*i]){
                visited[*i]=true;
                queue.push_back(*i);
            }
        }
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
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.BFS(2);
    cout<<endl;
	return 0;
}