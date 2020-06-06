#include <iostream>
#include <stack>

#define MAX 1000
using namespace std;

class queue{
    int top;
public:
    queue(){
        top=-1;
    }
    stack<int> s1;
    stack<int> s2;
    void push(int);
    int pop();
};

void queue::push(int x){
    if(top>=(MAX-1)){
        cout<<"Stack Overflow";
        return;
    }
    top++;
    s1.push(x);
}

int queue::pop(){
    if(top<0){
        cout<<"Stack Underflow";
        return -1;
    }
    if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    int res=s2.top();
    s2.pop();
    top--;
    return res;

    /* Recursive way
    int x=s.top();
    s.pop();
    if(s.empty()){
        return x;
    }
    int item=pop();
    s.push(x);
    return item;
    */

}


int main() 
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.pop()<<" ";
    cout<<q.pop()<<" ";
    cout<<q.pop()<<" ";
    cout<<endl;
	return 0; 
} 
