#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class graph{
    int V;
    list<int> *adj;
public:
    graph(int V){
        this->V = V;
        adj = new list<int> [V];
    }

    void addedge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int BFS(int n1, int n2);
};

int graph::BFS(int n1, int n2){
    int visited[V]; 
    memset(visited, 0, sizeof(visited));

    queue<int> que;

    visited[n1]=1;

    que.push(n1);

    list<int>::iterator i;

    while(!que.empty()){
        int q = que.front();
        que.pop();

        for(i=adj[q].begin();i!=adj[q].end();i++){
            if(!visited[*i]){
                visited[*i] = visited[q] + 1;
                que.push(*i);
            }
            if(*i==n2){
                return (visited[*i]-1);
            }
        }
    }
    return 0;
}

void SieveOfEratosthenes(vector<int> &v){
    int n = 9999;
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for(int p=2;p*p<=n;p++){
        if(prime[p]){
            for(int i=p*p;i<=n;i+=p){
                prime[i]=false;
            }
        }
    }

    for(int i=1000;i<=n;i++){
        if(prime[i]){
            v.push_back(i);
        }
    }
}

bool compare(int a, int b){
    string s1 = to_string(a);
    string s2 = to_string(b);

    int c=0;
    if (s1[0] != s2[0]) 
        c++; 
    if (s1[1] != s2[1]) 
        c++; 
    if (s1[2] != s2[2]) 
        c++; 
    if (s1[3] != s2[3]) 
        c++;
    return (c==1);
}

int shortestPath(int n1, int n2){
    vector<int> pset;//all 4 digit primes generation using sieveOfEratosthenes
    SieveOfEratosthenes(pset);

    graph g(pset.size());

    for(int i=0;i<pset.size();i++){
        for(int j=i+1;j<pset.size();j++){
            if (compare(pset[i], pset[j])) 
                g.addedge(i, j);
        }
    }

    //we have to find the pos of number 1 and 2 to start BFS
    int int1,int2;
    for(int j=0;j<pset.size();j++){
        if(pset[j]==n1)
            int1=j;
    }

    for(int j=0;j<pset.size();j++){
        if(pset[j]==n2)
            int2=j;
    }

    return g.BFS(int1,int2);
}

int main() {
    int num1 = 1033, num2 = 8179; 
    cout << shortestPath(num1, num2);
    cout<<endl;
	return 0;
}