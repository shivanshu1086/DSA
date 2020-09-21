#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void printLevels(vector<int> graph[], int V){
    vector<bool> visited(V,false);

    int level[V];
    memset(level,0,sizeof(level));

    queue<int> q;
    q.push(0);
    visited[0]=true;
    level[0]=0;
    while(!q.empty()){
        int f = q.front();
        q.pop();

        for(auto i=graph[f].begin();i!=graph[f].end();i++){
            if(!visited[*i]){
                level[*i] = level[f] + 1;
                visited[*i]=true;
                q.push(*i);
            }
        }
    }

    for(int i=0;i<V;i++){
        cout<<i<<"  -->  "<<level[i]<<endl;
    }
}

int main(){
    int V=8;
    vector<int> graph[V];
    graph[0].push_back(1); 
    graph[0].push_back(2); 
    graph[1].push_back(3); 
    graph[1].push_back(4); 
    graph[1].push_back(5); 
    graph[2].push_back(5); 
    graph[2].push_back(6); 
    graph[6].push_back(7);

    printLevels(graph,V);
    cout<<endl;
	return 0;
}