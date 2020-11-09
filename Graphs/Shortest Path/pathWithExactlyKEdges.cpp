#include <iostream>

using namespace std;
#define V 4 
#define INF INT_MAX 

int shortestPath(int graph[][V], int u, int v, int k){
    int sp[V][V][k+1];

    for(int e=0;e<=k;e++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                sp[i][j][e] = INF;

                if (e == 0 && i == j) 
                    sp[i][j][e] = 0;
                
                if (e == 1 && graph[i][j] != INF) 
                    sp[i][j][e] = graph[i][j];

                if(e>1){
                    for(int a=0;a<V;a++){
                        if (graph[i][a] != INF && i != a && j!= a && sp[a][j][e-1] != INF){
                            sp[i][j][e] = min(sp[i][j][e], graph[i][a] + sp[a][j][e-1]);
                        }
                    }
                }
            }
        }
    }
    return sp[u][v][k];
}
//recursion
// int shortestPath(int graph[][V], int u, int v, int k) 
// { 
//    // Base cases 
//    if (k == 0 && u == v)             return 0; 
//    if (k == 1 && graph[u][v] != INF) return graph[u][v]; 
//    if (k <= 0)                       return INF; 
  
//    // Initialize result 
//    int res = INF; 
  
//    // Go to all adjacents of u and recur 
//    for (int i = 0; i < V; i++) 
//    { 
//        if (graph[u][i] != INF && u != i && v != i) 
//        { 
//            int rec_res = shortestPath(graph, i, v, k-1); 
//            if (rec_res != INF) 
//               res = min(res, graph[u][i] + rec_res); 
//        } 
//    }
//    return res; 
// } 


int main(){
    int graph[V][V] = { {0, 10, 3, 2}, 
                        {INF, 0, INF, 7}, 
                        {INF, INF, 0, 6}, 
                        {INF, INF, INF, 0} 
                      }; 
    int u = 0, v = 3, k = 2; 
    cout << shortestPath(graph, u, v, k);
    cout<<endl;
    return 0;
}