#include <iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

void arrange(int *a, int n){//quick sort pivot as 0
	int i=-1;
	for(int j=0;j<n;j++){
		if(a[j]<0){
			i++;
			swap(a[i],a[j]);
		}
	}
}

void rearrange(int *a, int n){
	int key,j;
	for(int i=1;i<n;i++){
		key=a[i];
		if(key>0){
			continue;
		}
		j=i-1;
		while(j>=0 && a[j]>0){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}

int main() 
{
	int a[]={ -12, 11, -13, -5, 6, -7, 5, -3, -6 };
	int n=sizeof(a)/sizeof(int);
	rearrange(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
    return 0;
}
