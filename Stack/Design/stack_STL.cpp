#include <iostream>
#include <stack>

using namespace std;

void showstack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main() 
{
    stack<int> s;
    s.push(10);    
    s.push(20);    
    s.push(30);    
    s.push(40);
    showstack(s);
    cout<<s.size();
    cout<<endl;
	return 0; 
} 
