#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<climits>
#include<vector>
#include<set>
#include<queue>
using namespace std;

int partition(int *a, int l, int r){
	int x=a[r];
	int i=l;
	for(int j=l;j<r;j++){
		if(x>=a[j]){
			swap(a[i],a[j]);
			i++;
		}
	}
	swap(a[i],a[r]);
	return i;
}

int randompartition(int *a, int l, int r){
	int n=r-l+1;
	int pivot=rand()%n;
	swap(a[l+pivot], a[r]);
	return partition(a,l,r);
}


int k_small(int *a, int l, int r, int k){
	if(k>0 && k<=r-l+1){
		int pos=randompartition(a,l,r);
		if(pos-l==k-1){
			return a[pos];
		}
		else if(pos-l>k-1){
			return k_small(a,l,pos-1,k);
		}
		return k_small(a,pos+1,r,k-pos+l-1);
	}
	return INT_MAX;
}//O(n) approach

int minheapmethod(int *a, int n, int k){
	priority_queue<int, vector<int>, greater<int> > mh;
	for(int i=0;i<n;i++){
		mh.push(a[i]);
	}
	int count=0;int ans=1;
	while(mh.empty()==false && count<k){
		ans*=mh.top();
		mh.pop();
		count++;
	}
	return ans;
}//O(n*logn) approach

int main() 
{
	int a[]={198, 76, 544, 123, 154, 675};
	int n=sizeof(a)/sizeof(a[0]);
	int ans=1;
	int k=2;
	for(int i=1;i<=k;i++){
		ans*=k_small(a,0,n-1,i);
	}
	cout<<ans;
	// cout<<minheapmethod(a,n,k);
	cout<<endl;
    return 0;
}
