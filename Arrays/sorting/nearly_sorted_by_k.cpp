#include <iostream>
#include<vector>
#include <cmath>
#include <queue>

using namespace std;

void nearly_sorted_by_k(int *a, int n, int k){
    priority_queue<int,vector<int>,greater<int> > minhp(a,a+k+1);
    int ary_index=0;
    for(int i=k+1;i<n;i++){
        a[ary_index++]=minhp.top();
        minhp.pop();
        minhp.push(a[i]);
    }
    while(!minhp.empty()){
        a[ary_index++]=minhp.top();
        minhp.pop();
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int main()
{
    int a[]={6, 5, 3, 2, 8, 10, 9};
    int n=sizeof(a)/sizeof(a[0]);
    nearly_sorted_by_k(a,n,3);
	cout<<endl;
    return 0;
}
