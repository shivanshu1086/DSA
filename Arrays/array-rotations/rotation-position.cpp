#include <iostream>
#include<string>
using namespace std;


int rotation_position(int *a, int n, int i){
	if(i>=n-1){
		return -1;
	}
	if(a[i]>a[i+1]){
		return i;
	}
	return rotation_position(a,n,i+1);
}

int binary_search(int *a, int low, int high){
	
	if(low>high){
		return 0;
	}
	if(high==low){
		return low;//or high
	}
	int mid=low+(high-low)/2;//same as (low+high)/2;
	if(mid<high && a[mid]>a[mid+1]){
		return mid+1;
	}
	if(mid>low && a[mid]<a[mid-1]){
		return mid;
	}
	if(a[mid]<a[high]){
		return binary_search(a,low,mid-1);
	}
	return binary_search(a,mid+1,high);
}

int main() 
{ 
    int n;
    cin>>n;
	//int a[]={15, 18, 2, 3, 6, 12};
	//int n=sizeof(a)/sizeof(int);
    int a[n];
	int largest=INT_MIN;
	int d=INT_MIN;
	for(int i=0;i<n;i++){
		int temp;cin>>temp;
		if(temp>largest){
			largest=temp;
			d=i;//one way
		}
		a[i]=temp;
	}
    cout<<d+1<<endl;//O(n);
	cout<<rotation_position(a,n,0)+1<<endl;//second way if input is already given
	cout<<binary_search(a,0,n-1);//O(Logn)
	cout<<endl;
    return 0; 
} 
