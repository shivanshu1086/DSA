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
	int query_type;
	int l;
	int r;
};


int arr[1000];

void type1(int start, int end){
	for(int i=start;i<=end;i++){
		arr[i]++;
	}
}

void type2(pairs *q, int start, int end){
	for(int i=start;i<=end;i++){
		if(q[i-1].query_type==1){
			type1(q[i-1].l,q[i-1].r);
		}
		else if(q[i].query_type==2){
			type2(q,q[i-1].l,q[i-1].r);
		}
	}
}

void array_creation(int n, int m, pairs *q){
	memset(arr,0,sizeof(arr));
	for(int i=0;i<m;i++){
		if(q[i].query_type==1){
			//query1
			type1(q[i].l,q[i].r);
		}
		else{
			//query2
			type2(q,q[i].l,q[i].r);
		}
	}
}

int main() 
{
	// int a[]={ 210, 11, 48, 22, 133 };
	int n=5;
	pairs q[]={{ 1, 1, 2 }, { 1, 4, 5 },{ 2, 1, 2 }, { 2, 1, 3 },{ 2, 3, 4 }};
	int m=sizeof(q)/sizeof(q[0]);
	array_creation(n,m,q);
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
    return 0;
}