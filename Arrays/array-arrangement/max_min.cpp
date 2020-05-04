#include <iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

void max_min(int *a, int n){//O(n) approach
	int right=n/2;
	int left=0;
	int r[n-right],l[right];
	for(int i=0,j=0,k=0;i<n;i++){
		if(i<right){
			l[j]=a[i];
			j++;
		}
		else{
			r[k]=a[i];
			k++;
		}
	}
	
	for(int i=0,j=n-right-1,k=0;i<n;i++){
		if(i%2==0){
			a[i]=r[j];
			j--;
		}
		else{
			a[i]=l[k];
			k++;
		}
	}
}

void large_small(int *a, int n){//O(n) approach
	int end=n-1;
	int start=0;
	int temp[n];
	for(int i=0;i<n;i++){
		if(i%2==0){
			temp[i]=a[end--];
		}
		else{
			temp[i]=a[start++];
		}
	}
	for(int i=0;i<n;i++){
		a[i]=temp[i];
	}
}

void rightrotate(int *a, int start, int end){
	while(start<end){
		swap(a[start],a[end]);
		start++;
		end--;
	}
}

void efficient_approach(int *a, int n){
	for(int i=0;i<n;i+=2){
		rightrotate(a,i,n-1);
		rightrotate(a,i+1,n-1);
	}
}

void most_efficient(int *a, int n){
	int max=a[n-1];
	int min=a[0];
	for(int i=0;i<n;i++){
		if(i%2==0){
			a[i]=max;
			max--;
		}
		else{
			a[i]=min;
			min++;
		}
	}
}

int main() 
{
	int a[]={1,2,3,4,5,6,7};
	int n=sizeof(a)/sizeof(int);
	// max_min(a,n);
	// large_small(a,n);//O(n) approach
	// efficient_approach(a,n);//o(1) & o(nlogn) approach
	most_efficient(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
    return 0;
}
