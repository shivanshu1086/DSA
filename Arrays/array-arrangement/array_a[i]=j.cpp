#include <iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

void change_position(int *a, int n){//O(n) space
	int temp[n];
	for(int i=0;i<n;i++){
		temp[a[i]]=i;
	}
	for(int i=0;i<n;i++){
		a[i]=temp[i];
	}
}
/*
For example, Suppose an element’s new value is 2, the old value is 1 and n is 3, then the
element’s value is stored as 1 + 2*3 = 7. We can retrieve its old value by 7%3 = 1 and its new value
by 7/3 = 2.
*/
void change_po(int *a, int n){//O(1) space
	int i=0;
	for(int i=0;i<n;i++){
		a[a[i]%n]+=i*n;
	}
	for(int i=0;i<n;i++){
		a[i]/=n;
	}
}

int main() 
{
	int a[]={2, 0, 1, 4, 5, 3};
	int n=sizeof(a)/sizeof(int);
	// change_position(a,n);
	change_po(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
    return 0;
}
