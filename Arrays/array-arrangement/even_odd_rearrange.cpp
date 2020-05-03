#include <iostream>
#include<string>
#include<cmath>
using namespace std;

void even_odd_rearrange(int *a, int n){
	int even=n/2;
	int odd=n-even;
	int copyarr[n];
	for(int i=0;i<n;i++){
		copyarr[i]=a[i];
	}
	sort(copyarr, copyarr + n);//sorting the aux array
	int i=odd-1;
	for(int j=0;j<n;j+=2){
		a[j]=copyarr[i];
		i--;
	}
	i=odd;
	for(int j=1;j<n;j+=2){
		a[j]=copyarr[i];
		i++;
	}
}


int main() 
{
	int a[]={1, 2, 1, 4, 5, 6, 8, 8};
	int n=sizeof(a)/sizeof(int);
	even_odd_rearrange(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
    return 0;
}
