#include <iostream>
#include<string>
#include<cmath>
using namespace std;

void pos_neg(int *a, int n){
	int i=-1;
	for(int j=0;j<n;j++){
		if(a[j]<0){
			i++;
			swap(a[i],a[j]);
		}
	}
	int pos=i+1;
	int neg=0;
	while(pos<n && neg<pos && a[neg]<0){
		swap(a[pos],a[neg]);
		pos++;
		neg+=2;
	}
}

void neg_pos(int *a, int n){
	int i=-1;
	for(int j=0;j<n;j++){
		if(a[j]>=0){
			i++;
			swap(a[i],a[j]);
		}
	}
	int neg=i+1;
	int pos=0;
	while(pos<n && neg>pos && a[neg]<0){
		swap(a[pos],a[neg]);
		pos+=2;
		neg++;
	}
}


int main() 
{
	int a[]={-1, 2, -3, 4, 5, 6, -7, 8, 9};
	int n=sizeof(a)/sizeof(int);
	pos_neg(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
    return 0;
}
