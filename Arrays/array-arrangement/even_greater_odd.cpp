#include <iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

void even_greater_odd(int *a, int n){
	int copy[n];
	for(int i=0;i<n;i++){
		copy[i]=a[i];
	}
	sort(copy,copy+n);
	int start=0, end=n-1;
	for(int i=0;i<n;i++){
		if(i%2==0){
			a[i]=copy[start++];
		}
		else{
			a[i]=copy[end--];
		}
	}
}

int main() 
{
	int a[]={2, 1, 5, 6, 3};
	int n=sizeof(a)/sizeof(int);
	even_greater_odd(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
    return 0;
}
