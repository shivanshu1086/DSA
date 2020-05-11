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

int gcd(int a, int b){
	if(a==0){
		return b;
	}
	return gcd(b%a,a);
}

void fill_prefix_suffix(int *a, int *prefix, int *suffix, int n){
	prefix[0]=a[0];
	//Filling the prefix array following relation 
    // prefix(i) = __gcd(prefix(i-1), arr(i)) 
	for(int i=1;i<n;i++){
		prefix[i]=gcd(prefix[i-1],a[i]);
	}
	// Filling the suffix array following the 
    // relation suffix(i) = __gcd(suffix(i+1), arr(i)) 
	suffix[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--){
		suffix[i]=gcd(suffix[i+1],a[i]);
	}
}

void queries(pairs *q, int *prefix, int *suffix, int m, int n){
	for(int i=0;i<m;i++){
		int from=q[i].from;
		int to=q[i].to;
		if(from==0){
			cout<<suffix[to+1]<<endl;
			continue;
		}
		if(to==n-1){
			cout<<prefix[from-1]<<endl;
			continue;
		}
		else{
			cout<<gcd(prefix[from-1],suffix[to+1])<<endl;
			continue;
		}
	}
}

int main() 
{
	int a[]={2, 6, 9};
	int n=sizeof(a)/sizeof(a[0]);
	int prefix[n],suffix[n];
	pairs q[]={{0,0},{1,1},{1,2}};
	int m=sizeof(q)/sizeof(q[0]);
	fill_prefix_suffix(a,prefix,suffix,n);
	queries(q,prefix,suffix,m,n);
	cout<<endl;
    return 0;
}