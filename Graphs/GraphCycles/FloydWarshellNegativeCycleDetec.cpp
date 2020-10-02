#include <iostream>

#define V 4
#define INF 99999
using namespace std;

bool negCyclefloydWarshall(int graph[][V]){
    int dist[V][V], i, j, k;

    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            dist[i][j] = graph[i][j];
        }
    }

    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            for(k=0;k<V;k++){
                if(dist[j][k]>dist[j][i]+dist[i][k]){ //!via path min((j->k),(j->i i->k))
                    dist[j][k] = dist[j][i]+dist[i][k];
                }
            }
        }
    }

    for(i=0;i<V;i++){
        if(dist[i][i]<0){
            return true;
        }
    }

    return false;
}

int main(){
    int graph[V][V] = { {0   , 1   , INF , INF}, 
                        {INF , 0   , -1  , INF}, 
                        {INF , INF , 0   ,  -1}, 
                        {-1  , INF , INF ,   0}};
    
    if (negCyclefloydWarshall(graph)) 
       cout << "Yes"; 
    else
       cout << "No";
    cout<<endl;
    return 0;
}