#include <iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

void rearrange(int *a, int n){
	int count=0;
	for(int i=0;i<n;i++){
		if(a[i]!=0){
			swap(a[count++],a[i]);
		}
	}
}

void double_the_first(int *a, int n){
	for(int i=0;i<n-1;i++){
		if(a[i]!=0){
			if(a[i]==a[i+1]){
				a[i]=a[i]*2;
				a[i+1]=0;
				i++;
			}
		}
	}
	rearrange(a,n);
}

int main() 
{
	int a[]={0, 2, 2, 2, 0, 6, 6, 0, 0, 8};
	int n=sizeof(a)/sizeof(int);
	double_the_first(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
    return 0;
}
