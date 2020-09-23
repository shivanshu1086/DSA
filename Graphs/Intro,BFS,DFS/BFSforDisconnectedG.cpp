#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
}

void BFSUtil(int u, vector<int> adj[], 
            vector<bool> &visited) 
{
    queue<int> q;

    q.push(u);
    visited[u] = true;

    while(!q.empty()){
        u = q.front(); 
        cout << u << " "; 
        q.pop();

        for(int i=0;i<adj[u].size();i++){
            if(!visited[adj[u][i]]){
                visited[adj[u][i]] = true; 
                q.push(adj[u][i]);
            }
        }
    }
}

void BFS(vector<int> adj[], int V) 
{
    vector<bool> visited(V, false);

    for(int u=0;u<V;u++){
        if (visited[u] == false) 
            BFSUtil(u, adj, visited);
    }
}

int main(){
    int V = 5; 
    vector<int> adj[V]; 
  
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    BFS(adj, V);
    cout<<endl;
	return 0;
}