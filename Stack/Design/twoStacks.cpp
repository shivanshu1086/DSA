#include <iostream>
#include <stack>
#include <climits>

// #define MAX 1000
using namespace std;

class twoStacks{
    int *a, size;
    int i,j;
public:
    twoStacks(int n){
        size=n;
        a = new int[n];
        i=-1;
        j=size;
    }

    void push1(int x){
        if(i<j-1){
            i++;
            a[i]=x;
        }
        else{
            cout<<"Stack Overflow";
            exit(1);
        }
    }

    void push2(int x){
        if(i<j-1){
            j--;
            a[j]=x;
        }
        else{
            cout<<"Stack Overflow";
            exit(1);
        }
    }

    int pop1(){
        if(i<0){
            return -1;
        }
        int temp=a[i];
        i--;
        return temp;
    }
    
    int pop2(){
        if(j>size){
            return -1;
        }
        int temp=a[j];
        j++;
        return temp;
    }
};

int main() 
{
    twoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout<<ts.pop1()<<" ";
    ts.push2(40);
    cout<<ts.pop2();
    cout<<endl;
	return 0; 
} 
