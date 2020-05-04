#include <iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

void pos_neg(int *a, int n){
	int temp[n];
	int j=0;
	for(int i=0;i<n;i++){
		if(a[i]>0){
			temp[j++]=a[i];
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]<0){
			temp[j++]=a[i];
		}
	}
	for(int i=0;i<n;i++){
		cout<<temp[i]<<" ";
	}
}
// modified insertion sort
void efficient(int *a, int n){
	int key,j;
	for(int i=0;i<n;i++){
		key=a[i];
		if(key>0){//then shift all -ive to one position their right
			j=i-1;
			while(j>=0 && a[j]<0){
				a[j+1]=a[j];
				j--;
			}
			a[j+1]=key;
		}
	}
}

int main() 
{
	int a[]={1, -1, 3, 2, -7, -5, 11, 6 };
	int n=sizeof(a)/sizeof(int);
	// pos_neg(a,n);
	efficient(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
    return 0;
}
