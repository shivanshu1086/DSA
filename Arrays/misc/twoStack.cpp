#include <iostream>
#include <map>
#include <cmath>

using namespace std;

class twoStack{

    int *arr;
    int size;
    int top1,top2;

public:
    twoStack(int n){
        size=n;
        arr=new int[n];
        top1=-1;
        top2=size;
    }

    void push1(int x){
        if(top1<top2-1){
            top1++;
            arr[top1]=x;
        }
        else{
            cout<<"Overflow";
            exit(1);
        }
    }

    void push2(int x){
        if(top1<top2-1){
            top2--;
            arr[top2]=x;
        }
        else{
            cout<<"Overflow";
            exit(1);
        }
    }

    int pop1(){
        if(top1>=0){
            int x=arr[top1--];
            return x;
        }
        else{
            cout<<"Underflow";
            exit(1);
        }
    }

    int pop2(){
        if(top2<size){
            int x=arr[top2++];
            return x;
        }
        else{
            cout<<"Underflow";
            exit(1);
        }
    }
};

int main()
{
    twoStack t1(5);
    t1.push1(5);
    t1.push2(10);
    t1.push2(15);
    t1.push1(11);
    t1.push2(7);
    cout << "Popped element from stack1 is " << t1.pop1()<<endl;
    t1.push2(40);
    cout << "Popped element from stack1 is " << t1.pop2();
	cout<<endl;
    return 0;
}
