#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <utility>

#define pii pair<int,int>
#define mp make_pair

using namespace std;

void BFS(int j1, int j2, int target){
    map<pii,int> m;
    bool isSolvable = false;
    vector<pii> path;

    queue<pii> q;
    q.push(mp(0,0));

    while(!q.empty()){
        pii u = q.front();
        q.pop();

        if(m[u]==1){
            continue;
        }

        if(u.first>j1 || u.second>j2 || u.first<0 || u.second<0){
            continue;
        }

        path.push_back(u);//path construction

        m[u]=1;//marking as visited


        if(u.first==target || u.second==target){
            isSolvable=true;

            if(u.first==target){
                if(u.second!=0)
                    path.push_back(pii(u.first,0));
            }
            else{
                if(u.first!=0){
                    path.push_back(pii(0,u.second));
                }
            }

            for(auto i:path){
                cout << "(" << i.first 
                    << ", " << i.second << ")\n";
            }
            break;
        }

        q.push(pii(u.first,j1));
        q.push(pii(j2,u.second));

        for(int ap=0;ap<=max(j1,j2);ap++){
            int c = u.first + ap;
            int d = u.second - ap;

            //!if this poosible
            if(c==j1 || (d==0 && d>=0)){
                q.push(pii(c,d));
            }

            c = u.first - ap;
            d = u.second + ap;

            if((c==0 && c>=0) && d==j2){
                q.push(pii(c,d));
            }
        }

        q.push(pii(j1,0));
        q.push(pii(0,j2));
    }

    if (!isSolvable) 
        cout << "No solution";
}

int main(){
    int Jug1 = 4, Jug2 = 3, target = 2; 
    cout << "Path from initial state "
            "to solution state :\n"; 
    BFS(Jug1, Jug2, target);
    cout<<endl;
	return 0;
}