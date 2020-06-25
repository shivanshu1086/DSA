#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

bool pairWiseConsecutive(stack<int> s){
    stack<int> aux;
    while(!s.empty()){
        aux.push(s.top());
        s.pop();
    }
    bool result=true;

    while(aux.size()>1){
        int x=aux.top();
        aux.pop();
        int y=aux.top();
        aux.pop();

        if(abs(x-y)!=1){
            return false;
        }

        s.push(x);
        s.push(y);
    }
    if(aux.size()==1){
            s.push(aux.top());
    }
    return true;
}

int main() {
    stack<int> s; 
    s.push(4); 
    s.push(5); 
    s.push(-2); 
    s.push(-3); 
    s.push(11); 
    s.push(10); 
    s.push(5); 
    s.push(6); 
    s.push(20); 
  
    if (pairWiseConsecutive(s)) 
        cout << "Yes" << endl; 
    else
        cout << "No" << endl;
    cout<<endl;
	return 0;
}