#include <iostream>
#include <stack>
#include <climits>

#define MAX 1000
using namespace std;

class SpecialStack{
    stack<int> s;
    stack<int> aux;
public:
    
    void push(int x){
        if(s.empty()){
            s.push(x);
            aux.push(x);
        }
        if(x<aux.top()){
            aux.push(x);
            s.push(x);
        }
        else{
            s.push(x);
            aux.push(aux.top());
        }
    }

    void pop(){
        s.pop();
        aux.pop();
    }

    int top(){
        return s.top();
    }

    bool empty(){
        return s.empty();
    }

    int size(){
        return s.size();
    }

    int get_min(){
        return aux.top();
    }
};

int main() 
{
    SpecialStack s;
    s.push(18);
    s.push(19);
    s.push(29);
    s.push(15);
    s.push(16);
    cout<<s.get_min()<<endl;
    s.pop();
    s.pop();
    cout<<s.get_min();
    cout<<endl;
	return 0; 
} 
