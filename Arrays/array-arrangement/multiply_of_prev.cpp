#include <iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

void multiply_of_prev(int *a, int n){//O(n) space
	if(n>0){
		int temp[n];
		for(int i=0;i<n;i++){
			temp[i]=a[i];
		}
		a[0]=a[0]*a[1];
		a[n-1]=a[n-1]*a[n-2];
		for(int i=1;i<n-1;i++){
			a[i]=temp[i-1]*temp[i+1];
		}
	}
}

void efficient(int *a, int n){
	if(n>0){
		int prev=a[0];
		a[0]=a[0]*a[1];
		for(int i=1;i<n-1;i++){
			int cur=a[i];
			a[i]=prev*a[i+1];
			prev=cur;
		}
		a[n-1]=prev*a[n-1];
	}
}

int main() 
{
	int a[]={2, 3, 4, 5, 6};
	int n=sizeof(a)/sizeof(int);
	// multiply_of_prev(a,n);
	efficient(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
    return 0;
}
