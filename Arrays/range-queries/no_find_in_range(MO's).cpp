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
	int x;
};
int root[100];

int find(int x){
	return x==root[x]?x:root[x]=find(root[x]);
}

void uni(int x, int y){
	int p=find(x),q=find(y);
	if(p!=q){
		root[p]=root[q];
	}
}

void initialize_array(int *a, pairs *q, int n, int m){
	for(int i=0;i<n;i++){
		root[i]=i;
	}

	for(int i=1;i<n;i++){
		if(a[i]==a[i-1]){
			uni(i,i-1);
		}
	}
}

void array_creation(int *a, int n, int m, pairs *q){
	initialize_array(a,q,n,m);
	for(int i=0;i<m;i++){
		int l=q[i].l;
		int r=q[i].r;
		int flag=0;
		int x=q[i].x;
		int p=r;

		while(p>=l){
			if(a[p]==x){
				flag=1;
				break;
			}
			p=find(p)-1;
		}
		if(flag!=0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}

int main() 
{
	int a[]={ 1, 1, 5, 4, 5 };
	int n=sizeof(a)/sizeof(a[0]);
	pairs q[]={{ 0, 2, 2 }, { 1, 4, 1 }, { 2, 4, 5 } };
	int m=sizeof(q)/sizeof(q[0]);
	array_creation(a,n,m,q);
	cout<<endl;
    return 0;
}