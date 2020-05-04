//fisher_yates is to reorder the array in random order in O(n) time
#include <iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

void fisher_yates(int *a, int n){
	srand(time(NULL));//diff every time
	for(int i=n-1;i>0;i--){
		int j=rand()%(i+1);
		swap(a[i],a[j]);
	}
}

int main() 
{
	int a[]={2, 3, 4, 5, 6};
	int n=sizeof(a)/sizeof(int);
	fisher_yates(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
    return 0;
}
