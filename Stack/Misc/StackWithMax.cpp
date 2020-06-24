#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class StackWithMax{
public:
    stack<int> main;
    stack<int> currMax;

    void push(int x){
        main.push(x);
        if(main.size()==1){
            currMax.push(x);
            return;
        }
        else if(x>currMax.top()){
            currMax.push(x);
        }
        else{
            currMax.push(currMax.top());
        }
    }

    void pop(){
        main.pop();
        currMax.pop();
    }

    int getMax(){
        return currMax.top();
    }
};

int main() {
    StackWithMax s; 
    s.push(20); 
    cout << s.getMax() << endl; 
    s.push(10); 
    cout << s.getMax() << endl; 
    s.push(50); 
    cout << s.getMax() << endl;
    cout<<endl;
	return 0;
}