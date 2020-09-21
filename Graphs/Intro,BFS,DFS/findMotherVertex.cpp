#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    void DFSUtil(vector<bool> &visited, int i);
public:
    Graph(int V);
    void addEdge(int u, int v);
    int findMother();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int> [V];
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

void Graph::DFSUtil(vector<bool> &visited, int i){
    visited[i]=true;

    for(auto itr=adj[i].begin();itr!=adj[i].end();itr++){
        if(!visited[*itr]){
            DFSUtil(visited,*itr);
        }
    }
}

int Graph::findMother(){
    vector <bool> visited(V, false);
    int v=0;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            DFSUtil(visited,i);
            v=i;
        }
    }

    //!now v can be our mother vertex so check DFS taking v as source

    fill(visited.begin(),visited.end(),false);
    DFSUtil(visited,v);
    for(auto i:visited){
        if(i==false){
            return -1;
        }
    }
    return v;
}

int main() {
    Graph g(7); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(4, 1); 
    g.addEdge(6, 4); 
    g.addEdge(5, 6); 
    g.addEdge(5, 2); 
    g.addEdge(6, 0);

    cout << "A mother vertex is " << g.findMother();
    cout<<endl;
	return 0;
}