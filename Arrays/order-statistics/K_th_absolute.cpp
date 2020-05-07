#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<climits>
#include<vector>
#include<set>
#include<queue>
using namespace std;

int countpairs(int *a, int n, int mid){
	int count=0;
	for(int i=0;i<n;i++){
		count+=upper_bound(a+i,a+n,a[i]+mid)-(a+i+1);
	}
	return count;
}

int k_th_absolute(int *a, int n, int k){
	sort(a,a+n);
	if(n>1){
		int low=a[1]-a[0];
		int high=a[n-1]+a[0];
		for(int i=1;i<n-1;i++){
			low=min(low,a[i+1]-a[i]);
		}
		while(low<high){
			int mid=(low+high)>>1;//same as dividing with 2
			if(countpairs(a,n,mid)<k){
				low=mid+1;
			}
			else{
				high=mid;
			}
		}
		return low;
	}
	return INT_MIN;
}

int main() 
{
	int a[]={1,11,5, 2, 3, 4};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<k_th_absolute(a,n,3);
	cout<<endl;
    return 0;
}
