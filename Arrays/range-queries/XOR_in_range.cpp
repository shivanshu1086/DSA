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
#define MAX 2147483647 
int prefix[100001][32];

void make_prefix(int *a, int n){
	for(int j=0;j<32;j++){
		prefix[0][j]=0;
	}

	for(int i=1;i<=n;i++){
		int p=a[i-1];
		for(int j=0;j<32;j++){
			int x=pow(2,j);
			if(p&x){
				prefix[i][j]=1+prefix[i-1][j];
			}
			else{
				prefix[i][j]=prefix[i-1][j];
			}
		}
	}
}

void query_solver(pairs *q, int m){
	for(int i=0;i<m;i++){
		int l=q[i].l;
		int r=q[i].r;

		int tot_bts=r-l+1;
		int X=INT_MAX;

		for(int j=0;j<31;j++){
			int x=prefix[r][j]-prefix[l-1][i];
			if(x>=tot_bts-x){
				int ith_bit=pow(2,j);
				X=X^ith_bit;
			}
		}
		cout<<X<<endl;
	}
}

int main() 
{
	int a[]={ 210, 11, 48, 22, 133 };
	int n=sizeof(a)/sizeof(a[0]);
	pairs q[]={{1,3},{4,14},{2,4}};
	int m=sizeof(q)/sizeof(q[0]);
	// sort(a,a+n);//1,3,4,4,9,10
	make_prefix(a,n);
	query_solver(q,m);
	cout<<endl;
    return 0;
}