#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <queue>
#include<vector>
using namespace std;

void smallest_missing(int *a, int n, int m){
	unordered_map<int,int> um;
	for(int i=0;i<n;i++){
		um[a[i]]++;
	}
	for(int i=0;i<m;i++){
		if(um.find(i)!=um.end()){
			continue;
		}
		else{
			cout<<i;
			return;
		}
	}
}

//another way (modified binary search)

int smallest_missing2(int *a, int start, int end){
	if(start>end){
		return end+1;
	}
	if(start!=a[start]){
		return start;
	}
	int mid=(start+end)/2;

	if(mid==a[mid]){
		return smallest_missing2(a,mid+1,end);
	}
	return smallest_missing2(a,start,mid);
}

int main() 
{
	int a[]={0, 1, 2, 3, 4, 5, 6, 7, 10};
	int n=sizeof(a)/sizeof(a[0]);
	// smallest_missing(a,n,11);
	cout<<smallest_missing2(a,0,n-1);
	cout<<endl;
    return 0;
}
