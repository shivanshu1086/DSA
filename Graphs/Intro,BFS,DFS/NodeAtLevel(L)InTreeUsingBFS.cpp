#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int u, int v);
    int BFS(int s, int l);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int Graph::BFS(int s, int l){
    vector<bool> visited(V,false);

    int level[V];
    memset(level,0,sizeof(level));

    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    level[s]=0;

    while(!queue.empty()){
        s=queue.front();
        queue.pop_front();

        for(auto i=adj[s].begin();i!=adj[s].end();i++){
            if(!visited[*i]){
                level[*i] = level[s]+1;
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }

    int count = 0;
    for(int i=0;i<V;i++){
        if(level[i]==l){
            count++;
        }
    }
    return count;
}

int main() {
    Graph g(6); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(2, 4); 
    g.addEdge(2, 5); 
  
    int level = 2; 
  
    cout << g.BFS(0, level);
    cout<<endl;
	return 0;
}