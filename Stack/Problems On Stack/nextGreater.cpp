#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

void nextGreater(int *next, int *a, int n){
    stack<int> s;

    s.push(0);

    for(int i=1;i<n;i++){
        while(!(s.empty())){
            int curr=s.top();
            if(a[curr]<a[i]){
                next[curr]=i;
                s.pop();
            }
            else{
                break;
            }
        }
        s.push(i);
    }

    while(!(s.empty())){
        int cur = s.top();
        next[cur]=-1;
        s.pop();
    }
}

int answer_query(int q, int *next, int n, int *a){
    int pos = next[q];
    if(pos==-1){
        return -1;
    }
    else{
        return a[pos];
    }
}

int main() 
{
    int a[]={3, 4, 2, 7, 5, 8, 10, 6};
    int n=sizeof(a)/sizeof(a[0]);
    int q[]={3, 6, 1};
    int q_size=sizeof(q)/sizeof(q[0]);

    int next[n];
    memset(next,0,sizeof(next));
    nextGreater(next,a,n);

    for(int j=0;j<q_size;j++){
        cout<<answer_query(q[j],next,n,a)<<" ";
    }
    cout<<endl;
	return 0; 
}