#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <string>
#include <climits>
#include<vector>
using namespace std;

class pairs{
public:
	int l;
	int r;
};
int prefix[100];

void prefix_fill(int *a, int n){
	for(int i=0;i<n;i++){
		if(a[i]==a[i+1]){
			prefix[i]=1;
		}
		if(i!=0){
			prefix[i]+=prefix[i-1];
		}
	}
}

void query_ans(int *a, pairs *q, int n, int m){
	for(int i=0;i<m;i++){
		int l=q[i].l;
		int r=q[i].r;
		if(l==0){
			cout<<prefix[r-1]<<endl;
		}
		else{
			cout<<prefix[r-1]-prefix[l-1]<<endl;
		}
	}
}

int main() 
{
	int a[]={ 1, 2, 2, 2, 3, 3, 4, 4, 4 };
	int n=sizeof(a)/sizeof(a[0]);
	pairs q[]={{1,8},{0,4}};
	int m=sizeof(q)/sizeof(q[0]);
	prefix_fill(a,n);
	query_ans(a,q,n,m);
	cout<<endl;
    return 0;
}