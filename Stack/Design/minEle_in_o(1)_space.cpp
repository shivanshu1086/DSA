#include <iostream>
#include <stack>
#include <climits>

#define MAX 1000
using namespace std;

class MyStack{
public:
    stack<int> s;
    int minEle;


    void push(int x){
        if(s.empty()){
            minEle=x;
            s.push(x);
            return;
        }

        if(x<minEle){
            s.push(2*x-minEle);
            minEle=x;
        }
        else{
            s.push(x);
        }
    }

    void pop(){
        if(s.empty()){
            cout<<"Stack is empty"<< "\n";
            return;
        }
        int t=s.top();
        s.pop();

        if(t<minEle){
            cout<<minEle<< "\n";
            minEle=2*minEle-t;
        }
        else{
            cout<<minEle<< "\n";
        }
    }

    void peek(){
        if (s.empty()){ 
            cout << "Stack is empty "<< "\n"; 
            return; 
        }

        int t=s.top();
        (t < minEle) ? cout << minEle<< "\n": cout << t<< "\n";
    }

    void getMin(){ 
        if (s.empty()) 
            cout << "Stack is empty\n"; 
        else
            cout <<"Minimum Element in the stack is: "
                 << minEle << "\n"; 
    } 
};

int main() 
{
    MyStack s;
    s.push(3); 
    s.push(5); 
    s.getMin(); 
    s.push(2); 
    s.push(1); 
    s.getMin(); 
    s.pop(); 
    s.getMin(); 
    s.pop();
    s.peek();
    cout<<endl;
	return 0; 
} 
