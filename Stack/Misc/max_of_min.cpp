#include <iostream>
#include <stack>

using namespace std;

void max_of_min(int *a, int n){
    stack<int> s;

    int left[n+1];
    int right[n+1];

    //left and right initialization

    for(int i=0;i<n;i++){
        left[i]=-1;
        right[i]=n;
    }

    //left filling
    for(int i=0;i<n;i++){
        while(!s.empty() && a[s.top()]>=a[i]){
            s.pop();
        }
        if(!s.empty()){
            left[i]=s.top();
        }
        s.push(i);
    }

    while(!s.empty()){
        s.pop();
    }
    //right filling

    for(int i=n-1;i>=0;i--){
        while(!s.empty() && a[s.top()]>=a[i]){
            s.pop();
        }
        if(!s.empty()){
            right[i]=s.top();
        }
        s.push(i);
    }

    //answer array
    int ans[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=0;
    }

    for(int i=0;i<n;i++){
        int len = right[i]-left[i]-1;

        ans[len]=max(ans[len],a[i]);
    }

    //left entries
    for(int i=n-1;i>=1;i--){
        ans[i]=max(ans[i],ans[i+1]);
    }

    //print
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    int a[]={10, 20, 30, 50, 10, 70, 30};
    int n=sizeof(a)/sizeof(a[0]);
    max_of_min(a,n);
    cout<<endl;
	return 0; 
}