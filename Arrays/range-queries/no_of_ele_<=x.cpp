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
	int x;
	int idx;
};

class arrayelements{
public:
	int val;
	int idx;
};

bool cmp2(arrayelements a, arrayelements b){
	return a.val<b.val;
}

bool cmp1(pairs a, pairs b){
	return a.x<b.x;
}

void update(int *bit, int idx, int val, int n){
	for(;idx<=n;idx+=idx&-idx){
		bit[idx]+=val;
	}
}

int query(int *bit, int idx, int n){
	int sum=0;
	for(;idx>0;idx-=idx&-idx){
		sum+=bit[idx];
	}
	return sum;
}

void answerqueries(arrayelements *a, pairs *q, int n, int m){
	int bit[n+1];
	memset(bit,0,sizeof(bit));

	//array sorting with cmp2 function
	sort(a,a+n,cmp2);
	//pairs sorting with cmp1 function
	sort(q,q+m,cmp1);

	int curr=0;
	int ans[m];//array for storing results

	for(int i=0;i<m;i++){
		while(a[curr].val<=q[i].x && curr<n){
			update(bit,a[curr].idx+1,1,n);
			curr++;
		}
		ans[q[i].idx]=query(bit,q[i].r+1,n)-query(bit,q[i].l,n);
	}
	for(int i=0;i<m;i++){
		cout<<ans[i]<<endl;
	}
}

int main() 
{
	// int a[]={2, 6, 9};
	arrayelements a[]={{2,0},{3,1},{4,2},{5,3}};
	int n=sizeof(a)/sizeof(a[0]);
	pairs q[]={{0,2,2,0},{0,3,5,1}};
	int m=sizeof(q)/sizeof(q[0]);
	answerqueries(a,q,n,m);
	cout<<endl;
    return 0;
}