#include <iostream>
using namespace std;

const int V = 5;

void DFS(bool graph[][V], bool marked[], int n, int vert, int start, int &count){
    marked[vert] = true;

    if(n==0){
        marked[vert] = false;
        if(graph[vert][start]){
            count++;
            return;
        }
        else{
            return;
        }
    }

    for(int i=0;i<V;i++){
        if(!marked[i] && graph[vert][i]){
            DFS(graph,marked,n-1,i,start,count);
        }
    }

    marked[vert]=false;
}

int countCycles(bool graph[][V], int n){
    bool marked[V];
    memset(marked,0,sizeof(marked));

    int count=0;
    for(int i=0;i<V-(n-1);i++){
        DFS(graph, marked, n-1, i, i, count);
        marked[i] = true;
    }
    return count/2;
}

int main(){
    bool graph[][V] = {{0, 1, 0, 1, 0}, 
                      {1, 0, 1, 0, 1}, 
                      {0, 1, 0, 1, 0}, 
                      {1, 0, 1, 0, 1}, 
                      {0, 1, 0, 1, 0}}; 
    int n = 4; 
    cout << "Total cycles of length " << n << " are "
         << countCycles(graph, n);
    cout<<endl;
    return 0;
}