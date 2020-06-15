#include <iostream>
#include <stack>

using namespace std;

stack<int> s2;

void sort(int x){
    if(s2.empty() or x>s2.top()){
        s2.push(x);
        return;
    }

    int temp=s2.top();
    s2.pop();
    sort(x);
    s2.push(temp);
}

void sortStack(stack<int> s){
    while(!s.empty()){
        int temp=s.top();
        s.pop();
        sort(temp);
    }
}

int main(){
    stack<int> s;
    s.push(34);
    s.push(3);
    s.push(31);
    s.push(98);
    s.push(92);
    s.push(23);
    stack<int> p=s;
    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }
    cout<<endl;
    sortStack(s);
    while(!s2.empty()){
        cout<<s2.top()<<" ";
        s2.pop();
    }
    cout<<endl;
	return 0; 
}