#include <iostream>
#include <stack>
#include <climits>

#define MAX 1000
using namespace std;

class kStack{
    int arr[10];//stores the actual element
    int top[3];//stores the top element index of every stack
    int next[10];//stroes next entry in all stacks
    
    int n,k;
    int free;
public:
    kStack(int k1, int n1){
        k=k1;
        n=n1;

        // arr=new int[n];
        // top=new int[k];
        // next=new int[n];

        for(int i=0;i<k;i++){
            top[i]=-1;
        }

        free=0;
        for(int i=0;i<n-1;i++){
            next[i]=i+1;
        }
        next[n-1]=-1;
    }

    bool isfull(){
        return (free==-1);
    }

    bool isempty(int sn){
        return (top[sn]==-1);
    }

    void push(int x, int sn){
        if(isfull()){
            cout<<"Stack is full";
            return;
        }

        int i=free;
        free = next[i];

        next[i]=top[sn];
        top[sn]=i;

        arr[i]=x;
    }

    int pop(int sn){
        if(isempty(sn)){
            cout<<"Stack Underflow";
            return INT_MAX;
        }
        int i=top[sn];
        top[sn]=next[i];
        next[i]=free;
        free=i;
        return arr[i];
    }

};

int main() 
{
    kStack ks(3,10);
    ks.push(15,2);
    ks.push(45,2);

    ks.push(17, 1); 
    ks.push(49, 1); 
    ks.push(39, 1);

    ks.push(11, 0); 
    ks.push(9, 0); 
    ks.push(7, 0);

    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl; 
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;

    cout<<endl;
	return 0; 
} 
