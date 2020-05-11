#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <string>
#include <climits>
#include<vector>
using namespace std;

class pairs{
public:
	int l;
	int r;
};

int lowerbound(int *a, int n, int x){
	int l=0;int h=n-1;
	while(l<=h){
		int mid=(l+h)/2;
		if(a[mid]>=x){
			h=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return l;
}

int upperbound(int *a, int n, int y){
	int l=0;int h=n-1;
	while(l<=h){
		int mid=(l+h)/2;
		if(a[mid]<=y){
			//as we have sorted array so check right part
			l=mid+1;
		}
		else{
			h=mid-1;
		}
	}
	return h;
}

void countrange(int *a, pairs *q, int n, int m){
	for(int i=0;i<m;i++){
		int count=0;
		int x=q[i].l;
		int y=q[i].r;
		count=(upperbound(a,n,y)-lowerbound(a,n,x))+1;
		cout<<count<<endl;
	}
}


int main() 
{
	int a[]={ 1, 4, 4, 9, 10, 3 };
	int n=sizeof(a)/sizeof(a[0]);
	pairs q[]={{1,4},{9,12}};
	int m=sizeof(q)/sizeof(q[0]);
	sort(a,a+n);//1,3,4,4,9,10
	countrange(a,q,n,m);
	cout<<endl;
    return 0;
}