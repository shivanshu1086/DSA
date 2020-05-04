#include <iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;


void even_small_odd(int *a, int n){
	sort(a,a+n);
	int max=a[n-1];
	int min=a[0];
	for(int i=0;i<n;i++){
		if(i%2==0){
			a[i]=min;
			min++;
		}
		else{
			a[i]=max;
			max--;
		}
	}
}

void second_approach(int *a, int n){
	for(int i=0;i<n-1;i++){
		if(i%2==0 && a[i]>a[i+1]){
			swap(a[i],a[i+1]);
		}
		if(i%2!=0 && a[i]<a[i+1]){
			swap(a[i],a[i+1]);
		}
	}
}

int main() 
{
	int a[]={6, 4, 2, 1, 8, 3};
	int n=sizeof(a)/sizeof(int);
	// even_small_odd(a,n);
	second_approach(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
    return 0;
}
