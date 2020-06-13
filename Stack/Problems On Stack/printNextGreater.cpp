#include <iostream>
#include <string>
#include <stack>

using namespace std;

void printNextGreater(int *a, int n){
    stack<int> s;
    s.push(a[0]);
    for(int i=1;i<n;i++){
        if(s.empty()){
            s.push(a[i]);
        }

        while(!(s.empty()) && s.top()<a[i]){
            cout<<s.top()<<" --> "<<a[i]<< endl;
            s.pop();
        }
        s.push(a[i]);
    }
    while(!(s.empty())){
        cout<<s.top()<<" --> "<<"-1"<< endl;
        s.pop();
    }
}

int main() 
{
    int a[]={11, 13, 21, 3};
    int n=sizeof(a)/sizeof(a[0]);
    printNextGreater(a,n);
    cout<<endl;
	return 0; 
}