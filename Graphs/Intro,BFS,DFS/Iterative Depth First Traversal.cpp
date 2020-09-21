#include <iostream>
#include <list>
#include <vector>
#include <stack>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    void DFSUtil(vector<bool> &visited, int i);
public:
    Graph(int V);
    void addEdge(int u, int v);
    void DFS();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int> [V];
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

void Graph::DFS(){
    vector<bool> visited(V, false);
    for(int i=0;i<V;i++){
        DFSUtil(visited,i);
    }
}

void Graph::DFSUtil(vector<bool> &visited, int i){
    stack<int> stack;

    stack.push(i);

    while(!stack.empty()){
        i=stack.top();
        stack.pop();

        if(!visited[i]){
            cout<<i<<" ";
            visited[i]=true;
        }

        for(auto itr=adj[i].begin();itr!=adj[i].end();itr++){
            if(!visited[*itr]){
                stack.push(*itr);
            }
        }
    }
}

int main() {
    Graph g(5);
    g.addEdge(1, 0); 
    g.addEdge(2, 1); 
    g.addEdge(3, 4); 
    g.addEdge(4, 0);

    cout << "Following is Iterative Depth First Traversal\n"; 
    g.DFS();
    cout<<endl;
	return 0;
}