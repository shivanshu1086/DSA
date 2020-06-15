#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool checkSort(queue<int> &q, int n){
    stack<int> s;
    int expected = 1;
    int fnt;

    while(!q.empty()){
        fnt=q.front();
        q.pop();
        if(fnt==expected){
            expected++;
        }

        else{
            if(s.empty()){
                s.push(fnt);
            }
            else if(!s.empty() && s.top()<fnt){
                return false;
            }
            else{
                s.push(fnt);
            }
        }
        while(!s.empty() && s.top()==expected){
            s.pop();
            expected++;
        }
    }

    if(expected-1==n && s.empty()){
        return true;
    }
    return false;
}

int main(){
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    int n=q.size();
    (checkSort(q,n) ? cout<<"Yes" : cout<<"No");
    cout<<endl;
	return 0; 
}