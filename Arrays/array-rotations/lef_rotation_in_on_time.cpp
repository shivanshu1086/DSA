#include <iostream>
#include<string>
using namespace std;

void leftrotate(int *a, int n, int k){
	for(int i=0;i<n;i++){
		cout<<a[(i+k)%n]<<" ";
	}
	cout<<endl;
}

int main() 
{
	int a[]={1, 3, 5, 7, 9};
	int n=sizeof(a)/sizeof(int);
	int k=1;
	leftrotate(a,n,k);
	k=3;
	leftrotate(a,n,k);
	k=4;
	leftrotate(a,n,k);
	k=6;
	leftrotate(a,n,k);
	cout<<endl;
    return 0;
}