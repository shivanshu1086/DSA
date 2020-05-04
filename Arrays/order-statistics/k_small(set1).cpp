#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<climits>
#include<vector>

using namespace std;

int partition(int *a, int l, int r);

int k_smallest(int *a, int n, int k){
	sort(a,a+n);
	return a[k-1];
}//O(nlogn) approach

int k_small(int *a, int l, int r, int k){
	if(k>0 && k<=r-l+1){
		int pos=partition(a,l,r);
		if(pos-l==k-1){
			return a[pos];
		}
		if(pos-l>k-1){
			return k_small(a,l,pos-1,k);
		}
		return k_small(a,pos+1,r,k-pos+l-1);
	}
	return INT_MAX;
}//O(n) approach

int partition(int *a, int l, int r){
	int x=a[r];
	int i=l;
	for(int j=l;j<r;j++){
		if(a[j]<x){
			swap(a[i],a[j]);
			i++;
		}
	}
	swap(a[i],a[r]);
	return i;
}


int main() 
{
	int a[]={7, 10, 4, 3, 20, 15};
	int n=sizeof(a)/sizeof(int);
	cout<<k_small(a,0,n-1,3);
	// for(int i=0;i<n;i++){
	// 	cout<<a[i]<<" ";
	// }
	cout<<endl;
    return 0;
}
