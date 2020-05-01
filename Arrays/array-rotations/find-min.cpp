#include <iostream>
#include<string>
using namespace std;

int binary_search(int *a, int low, int high){
	if(low>high){
		return -1;
	}
	if(high==low){
		return low;
	}
	int mid=low+(high-low)/2;
	if(mid<high && a[mid]>a[mid+1]){
		return mid+1;
	}
	if(mid>low && a[mid]<a[mid-1]){
		return mid;
	}
	if(a[mid]>a[high]){
		return binary_search(a,low,mid-1);
	}
	return binary_search(a,mid+1,high);
}

int main() 
{ 
	int a[]={5, 6, 1, 2, 3, 4};
	int n=sizeof(a)/sizeof(int);
	int ans=binary_search(a,0,n-1);
	if(ans!=-1){
		cout<<a[ans];
	}
	else{
		cout<<"Not found";
	}
	cout<<endl;
    return 0;
} 
