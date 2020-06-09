#include <iostream>
#include <queue>
#include <climits>

#define MAX 1000
using namespace std;


class Stack{
public:
    int count;
    priority_queue<pair<int,int> > pq;

    Stack():count(0){}

    void push(int x){
        count++;
        pq.push(make_pair(count,x));
    }

    void pop(){
        if(pq.empty()){
            cout<<"Stack is empty";
            return;
        }
        count--;
        pq.pop();
    }

    int top(){
        return pq.top().second;
    }

    bool isEmpty(){
        return pq.empty();
    }
    
};

int main() 
{
    Stack *s=new Stack();
    s->push(1);
    s->push(2);
    s->push(3);

    while(!s->isEmpty()){ 
        cout<<s->top()<<endl; 
        s->pop(); 
    }
    cout<<endl;
	return 0; 
} 
