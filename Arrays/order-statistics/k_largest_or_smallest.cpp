//This method uses order statistics
#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<climits>
#include<vector>
#include<set>
using namespace std;

int partition(int *a, int l, int r){
	int x=a[r],i=l;//x is pivot
	for(int j=l;j<r;j++){
		if(a[j]>=x){
			swap(a[j],a[i]);
			i++;
		}
	}
	swap(a[i],a[r]);//pivot swap
	return i;
}

int randompartition(int *a, int l, int r){
	int n=r-l+1;
	int pivot=rand()%n;
	swap(a[l+pivot],a[r]);
	return partition(a,l,r);
}

int order_statistics(int *a, int l, int r, int k){
	if(k>0 && k<=r-l+1){
		int pos= randompartition(a,l,r);
		if(pos-l==k-1){
			return a[pos];
		}
		if(pos-l>k-1){
			return order_statistics(a,l,pos-1,k);
		}
		return order_statistics(a,pos+1,r,k-pos+l-1);
	}
	return INT_MAX;
}


void first_k_largest(int *a, int n, int k){//modified bubble sort
	// sort(a,a+n,comp);
	for(int i=0;i<k;i++){
		for(int j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				swap(a[j+1],a[j]);
			}
		}
	}
}

int main() 
{
	int a[]={12, 3, 5, 7, 4, 19, 26};
	int n=sizeof(a)/sizeof(int);
    // first_k_largest(a,n,3);
	for(int i=1;i<=n-1;i++)
	cout<<order_statistics(a,0,n-1,i)<<" ";
	// for(int i=n-1;i>3;i--){
	// 	cout<<a[i]<<" ";
	// }
	cout<<endl;
    return 0;
}
