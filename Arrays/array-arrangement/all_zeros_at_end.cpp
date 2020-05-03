#include <iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

void all_zeros(int *a, int n){
	int count=0;
	for(int i=0;i<n;i++){
		if(a[i]!=0){
			a[count]=a[i];
			count++;//maintaining the number of zeros to be pushed in the end
		}
	}
	while(count<n){
		a[count]=0;
		count++;
	}
}
//single loop approach
void single_loop(int *a, int n){
	int count=0;
	for(int i=0;i<n;i++){
		if(a[i]!=0){
			swap(a[count],a[i]);
			count++;
		}
	}
}

int main() 
{
	int a[]={1, 2, 0, 0, 0, 3, 6};
	int n=sizeof(a)/sizeof(int);
	// all_zeros(a,n);
	single_loop(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
    return 0;
}
