#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int length=0;
int top=-1;

int* createNew(int *a){
    int *a_new = new int[length+4];
    for(int i=0;i<length;i++){
        a_new[i]=a[i];
    }

    length+=4;
    return a_new;
}

int *push(int *a, int number){
    if(top==length-1){
        a = createNew(a);
    }
    a[++top]=number;
    return a;
}

void pop(){
    top--;
}

void display(int *a){
    if(top==-1){
        cout<<"Stack is empty";
    }
    else{
        for(int i=0;i<=top;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int *a = createNew(a);
    a = push(a,1);
    a = push(a,2);
    a = push(a,3);
    a = push(a,4);

    display(a);

    a = push(a,5);
    a = push(a,6);
    a = push(a,7);
    a = push(a,8);
    
    display(a);
    cout<<endl;
	return 0;
}