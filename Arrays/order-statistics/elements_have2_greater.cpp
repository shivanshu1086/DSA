#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<climits>
#include<vector>
#include<set>
using namespace std;

void maximum(int *a, int n, int k){
	// sort(a,a+n);
	// for(int i=0;i<n-2;i++){
	// 	cout<<a[i]<<" ";
	// }

	//efficient approach
	int first=INT_MIN;
	int second=INT_MIN;
	for(int i=0;i<n;i++){
		if(a[i]>first){
			second=first;
			first=a[i];
		}
		else if(a[i]>second){
			second=a[i];
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]<second){
			cout<<a[i]<<' ';
		}
	}
}

int main() 
{
	int a[]={20, 10, 20, 4, 100};
	int n=sizeof(a)/sizeof(a[0]);
	int k=4;
	maximum(a,n,k);
	cout<<endl;
    return 0;
}
