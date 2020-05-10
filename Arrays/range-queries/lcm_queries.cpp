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
};
int tree[1000];

int gcd(int a, int b){
	if(a==0){
		return b;
	}
	return gcd(b%a,a);
}

int lcm(int a, int b){
	return (a*b)/gcd(a,b);
}
void build_segment_tree(int *a, int node, int start, int end){
	if(start==end){
		tree[node]=a[start];
		return; 
	}

	int mid=(start+end)/2;

	//left and right segments
	build_segment_tree(a,2*node,start,mid);
	build_segment_tree(a,2*node+1,mid+1,end);

	//parent of left and right node
	tree[node]=lcm(tree[2*node],tree[2*node+1]);

}

int lcm_queries(int from , int to, int node, int start, int end){
		if(from>end || to<start){
			return 1;
		}//outside the range

		//inside the range completely starting to end
		if(from<=start && to>=end){
			return tree[node];
		}

		//partially inside
		int mid=(start+end)/2;
		int left_lcm=lcm_queries(from,to,2*node,start,mid);
		int right_lcm=lcm_queries(from,to,2*node+1,mid+1,end);
		return lcm(left_lcm,right_lcm);
}

void queries(int *a, pairs *q, int n, int m){
	for(int i=0;i<m;i++){
		int node=1,start=0,end=n-1;
		int from=q[i].from;
		int to=q[i].to;
		cout<<lcm_queries(from,to,node,start,end)<<endl;
	}
}

int main() 
{
	int a[]={5,7,5,2,10,12,11,17,14,1,44};
	int n=sizeof(a)/sizeof(a[0]);
	pairs q[]={{2, 5},{5, 10},{0, 10}};
	int m=sizeof(q)/sizeof(q[0]);
	build_segment_tree(a,1,0,n-1);
	queries(a,q,n,m);
	// for(int i=0;i<n;i++){
	// 	cout<<a[i]<<" ";
	// }
	cout<<endl;
    return 0;
}