#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<climits>
#include<vector>
#include<set>
using namespace std;

int maximum(int *a, int n){
	//Normal approach
	// int max=a[0];
	// for(int i=1;i<n;i++){
	// 	if(a[i]>max){
	// 		max=a[i];
	// 	}
	// }
	// return max;

	//bubble sort implementation
	for(int j=0;j<n-1;j++){
		if(a[j]>a[j+1]){
			swap(a[j],a[j+1]);
		}
	}
	return a[n-1];

	//STL approach
	// return *max_element(a,a+n);
}

int main() 
{
	int a[]={20, 10, 20, 4, 100};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<maximum(a,n);
	cout<<endl;
    return 0;
}
