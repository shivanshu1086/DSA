#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool check(int *a, int n){
    stack<int> s;
    int b_array=0;

    for(int i=0;i<n;i++){
        if(!s.empty()){
            int top=s.top();
            while(top==b_array+1){
                b_array++;
                s.pop();
                if(s.empty()){
                    break;
                }
                top=s.top();
            }

            if(s.empty()){
                s.push(a[i]);
            }

            else{
                top=s.top();
                if(a[i]<top){
                    s.push(a[i]);
                }
                else{
                    return false;
                }
            }
        }
        else{
            s.push(a[i]);
        }
    }
    return true;
}

int main(){
    int a[] = {4, 1, 2, 3};
    int n = sizeof(a)/sizeof(a[0]);
    check(a, n)? cout<<"YES": cout<<"NO"; 
    cout<<endl;
	return 0; 
}