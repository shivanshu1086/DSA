#include <iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

int min_swaps(int *a, int n, int k){
	int count=0;
	for(int i=0;i<n;i++){
		if(a[i]<=k){
			count++;
		}
	}//no of ele less than or equal to k
	int bad=0;
	for(int i=0;i<count;i++){
		if(a[i]>k){
			bad++;
		}
	}//sliding window
	int ans=bad;
	for(int i=0,j=count;j<n;i++,j++){
		if(a[i]>k){
			bad--;
		}
		if(a[j]>k){
			bad++;
		}
		ans=min(ans,bad);
	}
	return ans;
}

int main() 
{
	int a[]={2, 1, 5, 6, 3};
	int n=sizeof(a)/sizeof(int);
	cout<<min_swaps(a,n,3);
	// for(int i=0;i<n;i++){
	// 	cout<<a[i]<<" ";
	// }
	cout<<endl;
    return 0;
}
