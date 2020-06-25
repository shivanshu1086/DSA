#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

void interleave(queue<int> &q){

    if(q.size()%2!=0){
        cout<<"Please insert even elements";
        return;
    }
    stack<int> s;
    int halfSize=q.size()/2;

    for(int i=0;i<halfSize;i++){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }//enqueue back

    for(int i=0;i<halfSize;i++){
        q.push(q.front());
        q.pop();
    }//push again

    for(int i=0;i<halfSize;i++){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    for(int i=1;i<=10;i++){
        q.push(i);
    }
    interleave(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
	return 0;
}