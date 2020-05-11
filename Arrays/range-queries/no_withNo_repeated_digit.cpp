#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <unordered_set>
#include <string>
#include <climits>
#include<vector>
using namespace std;

class pairs{
public:
	int l;
	int r;
};

int repeated_digit(int n){
	unordered_set<int>s;
	while(n!=0){
		int d=n%10;
		if(s.find(d)!=s.end()){
			return 0;
		}
		s.insert(d);
		n=n/10;
	}
	return 1;
}

void query_selector(int *a, pairs *q, int n, int m){
	for(int i=0;i<m;i++){
		int l=q[i].l;
		int r=q[i].r;
		int answer=0;
		for(int i=l;i<=r;i++){
			answer+=repeated_digit(i);
		}
		cout<<answer<<endl;
	}
}

//efficient approach
vector <int> prefix={0};
int maxi=1000;

void prefix_calc(int maxi){
	prefix.push_back(repeated_digit(1));
	for(int i=2;i<=maxi;i++){
		prefix.push_back(repeated_digit(i)+prefix[i-1]);
	}
}

void prefix_query(int *a, pairs *q, int n, int m){
	prefix_calc(maxi);
	for(int i=0;i<m;i++){
		int l=q[i].l;
		int r=q[i].r;
		cout<<prefix[r]-prefix[l-1]<<endl;
	}
}

int main() 
{
	int a[]={ 5,10,25,34,6,2,11,19,22,4};
	int n=sizeof(a)/sizeof(a[0]);
	pairs q[]={{1,100},{1,5}};
	int m=sizeof(q)/sizeof(q[0]);
	// query_selector(a,q,n,m);//brute force
	prefix_query(a,q,n,m);
	cout<<endl;
    return 0;
}