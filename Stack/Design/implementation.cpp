#include <iostream>
#include <vector>
#define MAX 1000
using namespace std;

class Stack{
    int top;
public:
    Stack(){
        top=-1;
    }
    vector<int> v;
    void push(int);
    int pop();
    int peek();
    bool is_empty();
    void print();
};

void Stack::print(){
    for(int i=top;i>=0;i--){
        cout<<v[i]<<endl;
    }
}

void Stack::push(int x){
    if(top>=(MAX-1)){
        cout<<"Stack Overflow";
        return;
    }
    top++;
    v.push_back(x);
}

int Stack::pop(){
    if(top<0){
        cout<<"Stack Underflow";
        return -1;
    }
    return v[top--];
}

int Stack::peek(){
    if(top<0){
        cout<<"Empty Stack";
        return -1;
    }
    return v[top];
}

bool Stack::is_empty(){
    return (top<0);
}

int main() 
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.print();
    cout<<endl;
    cout<<s.pop();
    cout<<endl;
    s.print();
    cout<<endl;
    cout<<s.peek();
    cout<<endl;
    cout<<boolalpha<<s.is_empty();
    cout<<endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout<<boolalpha<<s.is_empty();
    cout<<endl;
	return 0; 
} 
