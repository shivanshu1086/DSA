#include <iostream>
#include <vector>

using namespace std;

int dfs(vector< pair<int, int> > g[], 
        pair<int, int> disRev[], bool visit[], int u) 
{
    visit[u] = true; 
    int totalRev = 0;

    for (int i = 0; i < g[u].size(); i++) 
    {
        int v = g[u][i].first;
        if(!visit[v]){
            disRev[v].first = disRev[u].first + 1;
            disRev[v].second = disRev[u].second;

            if (g[u][i].second) 
            { 
                disRev[v].second = disRev[u].second + 1; 
                totalRev++; 
            } 
            totalRev += dfs(g, disRev, visit, v);
        }
    }
    return totalRev;
}

void printMinEdgeReverseForRootNode(int edges[][2], int e) 
{ 
    int V = e+1;

    vector< pair<int, int> > g[V];
    pair<int, int> disRev[V];
    bool visit[V];

    int u, v; 
    for (int i = 0; i < e; i++) 
    { 
        u = edges[i][0]; 
        v = edges[i][1]; 
  
        // add 0 weight in direction of u to v 
        g[u].push_back(make_pair(v, 0)); 
  
        // add 1 weight in reverse direction 
        g[v].push_back(make_pair(u, 1)); 
    }

    for (int i = 0; i < V; i++) 
    { 
        visit[i] = false; 
        disRev[i].first = disRev[i].second = 0; 
    }

    int root = 0; 

    int totalRev = dfs(g, disRev, visit, root);

    int res = INT_MAX;

    for (int i = 0; i < V; i++) 
    { 
        // (reversal in path to i) + (reversal 
        // in all other tree parts) 
        int edgesToRev = (totalRev - disRev[i].second) + 
                         (disRev[i].first - disRev[i].second); 
  
        // choose minimum among all values 
        if (edgesToRev < res) 
        { 
            res = edgesToRev; 
            root = i; 
        } 
    }

    cout << root << " " << res << endl;
}

int main(){
    int edges[][2] = 
    { 
        {0, 1}, 
        {2, 1}, 
        {3, 2}, 
        {3, 4}, 
        {5, 4}, 
        {5, 6}, 
        {7, 6} 
    }; 
    int e = sizeof(edges) / sizeof(edges[0]); 
  
    printMinEdgeReverseForRootNode(edges, e);
    cout<<endl;
	return 0;
}