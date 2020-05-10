#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <climits>
#include<vector>
using namespace std;

class pairs{
public:
	int from;
	int to;
	int add;
};

void update_array(int *a, pairs *q, int n, int m){
	for(int i=0;i<m;i++){
		int from=q[i].from;
		int to=q[i].to;
		int add=q[i].add;
		a[from]+=add;
		if(to!=n-1)
		a[to+1]-=add;
	}

	//prefix sum
	for(int j=1;j<n;j++){
		a[j]+=a[j-1];
	}
}

int main() 
{
	int a[]={0,0,0,0,0,0};
	int n=sizeof(a)/sizeof(a[0]);
	pairs q[]={{0, 2, 100},{1, 5, 100},{2, 3, 100}};
	int m=sizeof(q)/sizeof(q[0]);
	update_array(a,q,n,m);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
    return 0;
}
