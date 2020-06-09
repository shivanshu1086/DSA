#include <iostream>
#include <queue>
#include <climits>

#define MAX 1000
using namespace std;

class Stack{
public:
    queue<int> q;

    void push(int x){
        int s=q.size();
        q.push(x);

        for(int i=0;i<s;i++){
            q.push(q.front());
            q.pop();
        }
    }

    void pop(){
        if(q.empty()){
            cout<<"Stack is empty";
            return;
        }
        else{
            q.pop();
        }
    }

    bool empty(){
        return q.empty();
    }

    int top(){
        return (q.empty())?-1:q.front();
    }
};

int main() 
{
    Stack s; 
    s.push(10); 
    s.push(20); 
    cout << s.top() << endl; 
    s.pop(); 
    s.push(30); 
    s.pop(); 
    cout << s.top() << endl; 
    cout<<endl;
	return 0; 
} 
