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
	int ele;
};

void naive_approach(int *a, pairs *q, int n, int m){
	for(int j=0;j<m;j++){
		int count=0;
		int l=q[j].from;
		int r=q[j].to;
		int ele=q[j].ele;
		for(int i=l-1;i<=r;i++){
			if(a[i]==ele){
				count++;
			}
		}
		cout<<count<<endl;
	}
}
//efficient technique

unordered_map<int,vector<int> > range;
void hashing_tech(int *a, pairs *q, int n, int m){
	for(int i=0;i<m;i++){
		int l=q[i].from;
		int r=q[i].to;
		int ele=q[i].ele;

		int a=lower_bound(range[ele].begin(),range[ele].end(),l)-range[ele].begin();//first position of left range
		int b=upper_bound(range[ele].begin(),range[ele].end(),r)-range[ele].begin();//last position the range of r
		cout<<b-a<<endl;
	}
	// for(auto i:range){
	// 	cout<<i.first<<"	 : "<<i.second[0]<<"  "<<i.second[1]<<" , "<<i.second[2]<<endl;
	// }
}

int main() 
{
	int a[]={2, 8, 6, 9, 8, 6, 8, 2, 11};
	int n=sizeof(a)/sizeof(a[0]);
	pairs q[]={{1,6,2},{4,9,8}};
	int m=sizeof(q)/sizeof(q[0]);
	// naive_approach(a,q,n,m);
	for(int i=0;i<n;i++){
		range[a[i]].push_back(i+1);
	}
	hashing_tech(a,q,n,m);
	cout<<endl;
    return 0;
}
