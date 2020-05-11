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
	int idx;
};
int block;
bool compare(pairs q1, pairs q2){
	if(q1.l/block!=q2.l/block){
		return q1.l/block<q2.l/block;
	}
	return q1.r<q2.r;
}

void remove(int x, int &currans, unordered_map<int,int> &mp){
	mp[x]--;//decrese the freq
	if(mp[x]==x){
		currans++;//if it is contributing
	}
	else if(mp[x]==(x-1)){
		currans--;//if it previously contributed.
	}
}

void add(int x, int &currans, unordered_map<int,int> &mp){
	mp[x]++;
	if(mp[x]==(x+1)){
		currans--;
	}
	else if(mp[x]==x){
		currans++;
	}
}

void query_iterator(int *a, pairs *q, int n, int m){
	block=(int)sqrt(n);
	sort(q,q+m,compare);
	int *ans=new int[m];
	unordered_map<int,int> mp;
	int currl=0,currr=0,currans=0;
	for(int i=0;i<m;i++){
		int l=q[i].l,r=q[i].r,idx=q[i].idx;
		while(currl<l){
			remove(a[currl],currans,mp);
			currl++;
		}


		while(currl>l){
			currl--;
			add(a[currl],currans,mp);
		}
		while(currr<=r){
			add(a[currr],currans,mp);
			currr++;
		}

		while(currr>r+1){
			currr--;
			remove(a[currr],currans,mp);
		}
		ans[idx]=currans;
	}
	for(int j=0;j<m;j++){
		cout<<ans[j]<<endl;
	}
}

int main() 
{
	int a[]={ 1,2,2,3,3,3 };
	int n=sizeof(a)/sizeof(a[0]);
	pairs q[]={{ 0, 1, 0 }, { 1, 1,1 }, { 0, 2,2 }, { 1, 3,3 }, { 3, 5,4 }, { 0, 5,5 }};
	int m=sizeof(q)/sizeof(q[0]);
	query_iterator(a,q,n,m);
	cout<<endl;
    return 0;
}