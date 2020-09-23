#include <iostream>
#include <vector>
#include <queue>
#define pb push_back 
using namespace std;
vector<bool> v; 
vector<vector<int> > g;

void edge(int u, int v){
    g[u].pb(v);
}

void bfs(int s){
    queue<int> q;
    q.push(s);
    v[s] = true;

    while(!q.empty()){
        int f = q.front(); 
        q.pop(); 
  
        cout << f << " "; 
  
        // Enqueue all adjacent of f and mark them visited  
        for (auto i = g[f].begin(); i != g[f].end(); i++) { 
            if (!v[*i]) { 
                q.push(*i); 
                v[*i] = true; 
            }
        }
    }
}

int main(){
    int n, e; 
    cin >> n >> e; 
  
    v.assign(n, false); 
    g.assign(n, vector<int>()); 
  
    int a, b; 
    for (int i = 0; i < e; i++) { 
        cin >> a >> b; 
        edge(a, b); 
    } 
  
    for (int i = 0; i < n; i++) { 
        if (!v[i]) 
            bfs(i); 
    }
    cout<<endl;
	return 0;
}