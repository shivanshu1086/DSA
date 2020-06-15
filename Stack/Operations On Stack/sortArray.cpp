#include <iostream>
#include <stack>

using namespace std;

stack<int> sortA(stack<int> s){
    stack<int> tmp;
    while(!s.empty()){
        int tmp_e=s.top();
        s.pop();
        while(!tmp.empty() && tmp.top()<tmp_e){
            s.push(tmp.top());
            tmp.pop();
        }
        tmp.push(tmp_e);
    }
    return tmp;
}

void sortArray(int *a, int n){
    stack<int> tmpStack;
    for(int i=0;i<n;i++){
        tmpStack.push(a[i]);
    }

    stack<int> tmp=sortA(tmpStack);
    
    for(int i=0;i<n;i++){
        a[i]=tmp.top();
        tmp.pop();
    }
}

int main(){
    int a[]={10,5,15,45};
    int n=sizeof(a)/sizeof(a[0]);
    sortArray(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
	return 0; 
}