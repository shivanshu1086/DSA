#include <iostream>
#include <stack>

using namespace std;

stack<int> s2;

stack<int> reverse_stack(stack<int> s){
    if(s.empty()){
        return s2;
    }
    s2.push(s.top());
    s.pop();
    return reverse_stack(s);
}

int main() 
{
    stack<int> s;
    for(int i=1;i<11;i++){
        s.push(i);
    }
    s=reverse_stack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
	return 0; 
}