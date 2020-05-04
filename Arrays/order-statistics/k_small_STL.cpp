#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<climits>
#include<vector>
#include<set>
using namespace std;

int k_small_STL(int *a, int n, int k){
	set<int> s;
	for(int i=0;i<n;i++){
		s.insert(a[i]);
	}
	auto it=s.begin();
	for(int i=0;i<k-1;i++){
		it++;
	}
	return *it;
}

int main() 
{
	int a[]={12, 3, 5, 7, 4, 19, 26};
	int n=sizeof(a)/sizeof(int);
    cout<<k_small_STL(a,n,3);
	// for(int i=0;i<n;i++){
	// 	cout<<a[i]<<" ";
	// }
	cout<<endl;
    return 0;
}
