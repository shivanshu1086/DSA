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

void precomputation(int *pre, int *a, int n){
	memset(pre,0,n*sizeof(int));
	pre[n-1]=a[n-1]*pow(2,0);
	for(int i=n-2;i>=0;i--){
		pre[i]=pre[i+1]+a[i]*(1<<(n-1-i));
	}
}

void queries(int *a, pairs *q, int n, int m, int *pre){
	for(int i=0;i<m;i++){
		int l=q[i].l;
		int r=q[i].r;
		if(r!=n-1){
			cout<<(pre[l]-pre[r+1])/(1<<(n-1-r))<<endl;
		}
		else{
			cout<<pre[l]/(1<<(n-1-r))<<endl;
		}
	}
}

int main() 
{
	int a[]={ 1, 0, 1, 0, 1, 1 };
	int n=sizeof(a)/sizeof(a[0]);
	pairs q[]={{2,4},{4,5}};
	int m=sizeof(q)/sizeof(q[0]);
	// sort(a,a+n);//1,3,4,4,9,10
	int pre[n];
	precomputation(pre,a,n);
	queries(a,q,n,m,pre);
	cout<<endl;
    return 0;
}