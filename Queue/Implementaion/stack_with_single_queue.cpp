#include <iostream>
#include <queue>

using namespace std;

class Stack{
    queue<int> q;
public:
    void push(int x){
        q.push(x);
    }

    int pop(){
        int t=q.back();
        while(q.front()!=t){
            q.push(q.front());
            q.pop();
        }
        q.pop();
        return t;
    }

    int top(){
        return q.back();
    }

};


int main(){
    Stack s;
    // for(int i=1;i<=10;i++){
    //     s.push(i);
    // }
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<endl;
	return 0;
}