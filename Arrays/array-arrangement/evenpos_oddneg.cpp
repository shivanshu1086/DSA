#include <iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

void evenpos_oddneg(int *a, int n){
	int onep=0;
	int secondp=1;
	while(onep<n && secondp<n){
		if(a[onep]<0 && a[secondp]>0){
			swap(a[onep],a[secondp]);
		}
		else{
			if(a[onep]>0){
				onep+=2;
			}
			if(a[secondp]<0){
				secondp+=2;
			}
		}
	}
}


int main() 
{
	int a[]={-1, 3, -5, 6, 3, 6, -7, -4, -9, 10};
	int n=sizeof(a)/sizeof(int);
	evenpos_oddneg(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
    return 0;
}
