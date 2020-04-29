#include <iostream>
#include<string>
using namespace std;



void leftrotation(int *a, int d, int n){
	for(int i=0;i<d;i++){
		int temp=a[n-1];
		for(int j=n-1;j>0;j--){
			a[j]=a[j-1];
		}
		a[0]=temp;
	}
}

int main()
{
	int n;
	cin>>n;
	int a[100];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int size;
	cin>>size;
	leftrotation(a,size,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	// cout<<a+n-size;
	cout<<endl;
    return 0;
}
