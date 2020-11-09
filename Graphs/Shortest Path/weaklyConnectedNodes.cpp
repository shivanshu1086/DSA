#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> Graph[10001];
set<int> node;

void dfs(bool *visit, int src){
    visit[src]=true;
    node.insert(src);
    int len = Graph[src].size();
    for(int i=0;i<len;i++){
        if(!visit[Graph[src][i]]){
            dfs(visit,Graph[src][i]);
        }
    }
}

int compute(int n){
    bool visit[n+5];
    memset(visit,false,sizeof(visit));

    int number_of_nodes=0;

    for(int i=0;i<n;i++){
        if(!visit[i]){
            node.clear();

            dfs(visit,i);

            int count=0;
            for(auto it=node.begin();it!=node.end();it++){
                count+=Graph[(*it)].size();
            }
            count /= 2;

            if(count==node.size()-1){
                number_of_nodes++;
            }
        }
    }
    return number_of_nodes;
}

void buildGraph(int *x, int *y, int len){
    for(int i=0;i<len;i++){
        int p=x[i];
        int q=y[i];
        Graph[p].push_back(q);
        Graph[q].push_back(p);
    }
}

int main(){
    int n=6,m=4;
    int x[9]= {1,1,4,4};
    int y[9]= {2, 3, 5, 6};

    buildGraph(x, y, n); 
    cout << compute(n) << " weakly connected nodes";

    cout<<endl;
    return 0;
}