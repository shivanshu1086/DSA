#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void printPath(vector<int> path){
    for(int i=0;i<path.size()-1;i++){
        cout<<path[i]<<"-->";
    }
    cout<<path[path.size()-1];
    cout << endl;
}

int notVisited(int x, vector<int>& path) 
{

    for(int i=0;i<path.size();i++){
        if (path[i] == x)  
            return 0;
    }
    return 1;
}

void findpaths(vector<vector<int> > &g, int src, int dest, int v){
    queue<vector<int> > q;

    vector<int> path;

    path.push_back(src); 
    q.push(path);

    while(!q.empty()){
        path = q.front();
        q.pop();

        int last = path[path.size()-1];

        if(last==dest){
            printPath(path);
        }
        else{
            for(int i=0;i<g[last].size();i++){
                if(notVisited(g[last][i],path)){
                    vector<int> newpath(path);
                    newpath.push_back(g[last][i]);
                    q.push(newpath);
                }
            }
        }
    }
}

int main(){
    vector<vector<int> > g;

    int v = 4; 
    g.resize(4);

    g[0].push_back(3); 
    g[0].push_back(1); 
    g[0].push_back(2); 
    g[1].push_back(3); 
    g[2].push_back(0); 
    g[2].push_back(1);

    int src = 2, dst = 3; 
    cout << "path from src " << src 
         << " to dst " << dst << " are \n";

    findpaths(g, src, dst, v);
    cout<<endl;
	return 0;
}