#include <iostream>
#include <vector>
#include <climits>
#include <stack>

using namespace std;

void bubbleSortWithStack(int a[], int n){
    stack<int> s1;
    stack<int> s2;
    for(int i=0;i<n;i++){
        s1.push(a[i]);
    }

    for(int i=0;i<n;i++){
        if(i%2==0){
            while(!s1.empty()){
                int t=s1.top();
                s1.pop();
                if(s2.empty()){
                    s2.push(t);
                }
                else{
                    if(s2.top()>t){
                        int temp=s2.top();
                        s2.pop();
                        s2.push(t);
                        s2.push(temp);
                    }
                    else{
                        s2.push(t);
                    }
                }
            }
            a[n-1-i]=s2.top();
            s2.pop();
        }
        else{
            while(!s2.empty()){
                int t=s2.top();
                s2.pop();
                if(s1.empty()){
                    s1.push(t);
                }
                else{
                    if(s1.top()>t){
                        int temp=s1.top();
                        s1.pop();
                        s1.push(t);
                        s1.push(temp);
                    }
                    else{
                        s1.push(t);
                    }
                }
            }
            a[n-1-i]=s1.top();
            s1.pop();
        }
    }

}

int main() {
    int a[]={15, 12, 44, 2, 5, 10};
    int n=sizeof(a)/sizeof(a[0]);
    bubbleSortWithStack(a,n);
    for(auto i:a){
        cout<<i<<" ";
    }
    cout<<endl;
	return 0;
}