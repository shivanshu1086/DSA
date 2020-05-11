#include <iostream>
#include <algorithm>
#include <map>
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

//MO's implementation
int block;

bool compare(pairs q1, pairs q2){
	if(q1.l/block!=q2.l/block){
		return q1.l/block<q2.l/block;
	}
	return q1.r<q2.r;
}

void mo_s_implementation(int *a, pairs *q, int n, int m){
	block=(int)sqrt(n);
	// sort the queries of same block together
	sort(q,q+m,compare);

	int currl=0,currr=0;
	map<int,int> mp;
	for(int i=0;i<m;i++){
		int l=q[i].l,r=q[i].r,x=q[i].x;
		// Decrement frequencies of extra elements 
        // of previous range. For example if previous 
        // range is [0, 3] and current range is [2, 5], 
        // then the frequencies of a[0] and a[1] are decremented 
		while(currl<l){
			mp[a[currl]]--;
			currl++;
		}

		// Increment frequencies of elements of current Range 
		while(currl>l){
			mp[a[currl-1]]++;
			currl--;
		}

		while(currr<=r){
			mp[a[currr]]++;
			currr++;
		}
		// Decrement frequencies of elements of previous 
        // range.  For example when previous range is [0, 10]  
        // and current range is [3, 8], then frequencies of  
        // a[9] and a[10] are decremented
		while(currr>r+1){
			mp[a[currr-1]]--;
			currr--;
		}

		if(mp[x]!=0){
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
	// array_creation(a,n,m,q);
	mo_s_implementation(a,q,n,m);
	cout<<endl;
    return 0;
}