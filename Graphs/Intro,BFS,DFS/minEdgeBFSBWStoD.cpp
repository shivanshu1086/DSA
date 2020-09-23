#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> g[], int u, int v){
    g[u].push_back(v);
    g[v].push_back(u);
}

int notVisited(int x, vector<int> path){
    for(int i=0;i<path.size();i++){
        if (path[i] == x)  
            return 0;
    }
    return 1;
}

int minEdgeBFS(vector<int> g[], int s, int d, int v){
    vector<int>path;

    queue<vector<int> > q;

    path.push_back(s);
    q.push(path);

    int min_dis = INT_MAX;

    while(!q.empty()){
        path = q.front();
        q.pop();
        int last = path[path.size()-1];
        if(last==d){
            if(path.size()<min_dis){
                min_dis = path.size();
            }
        }
        else{
            for(int i=0;i<g[last].size();i++){
                if(notVisited(g[last][i],path)){
                    vector<int> newPath(path);
                    newPath.push_back(g[last][i]);
                    q.push(newPath);
                }
            }
        }
    }
    return min_dis-1;
}

int main(){
    int n = 9; 
    vector <int> edges[9]; 
    addEdge(edges, 0, 1); 
    addEdge(edges, 0, 2);
    addEdge(edges, 0, 4);
    addEdge(edges, 1, 2);
    addEdge(edges, 2, 5);
    addEdge(edges, 3, 4);
    addEdge(edges, 4, 5);
    addEdge(edges, 6, 4);
    
    int u = 0; 
    int v = 5; 
    cout << minEdgeBFS(edges, u, v, n);
    cout<<endl;
	return 0;
}