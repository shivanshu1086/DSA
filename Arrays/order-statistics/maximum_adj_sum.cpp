#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <queue>
#include<vector>
using namespace std;

int maximum_adj_sum(int *a, int n){
	int incl=a[0];
	int excl=INT_MIN;
	int excl_new;
	for(int i=1;i<n;i++){
		excl_new = (incl > excl)? incl: excl;
		incl = excl + a[i]; 
     	excl = excl_new;
	}
	return ((incl > excl)? incl : excl);
}

int main() 
{
	int a[]={5, 5, 10, 100, 10, 5};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<maximum_adj_sum(a,n);
	cout<<endl;
    return 0;
}
