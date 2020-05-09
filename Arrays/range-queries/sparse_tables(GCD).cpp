#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <queue>
#include<numeric>
#include<vector>
using namespace std;

int lookup[500][500];

int gcd(int a, int b){
	if(b!=0){
		return gcd(b,a%b);
	}
	return a;
}

void buildsparsetable(int *a, int n){
	//gcd of single element is itself
	for(int i=0;i<n;i++){
		lookup[i][0]=a[i];
	}
	//now further table build
	for(int j=1;j<=n;j++){
		for(int i=0;i<=n-(1<<j);i++){
			lookup[i][j]=gcd(lookup[i][j-1],lookup[i+(1<<(j-1))][j-1]);
		}
	}
}

int query(int l, int r){
	int j=(int)log2(r-l+1);
	return (gcd(lookup[l][j],lookup[r-(1<<j)+1][j]));
}

int main() 
{
	int a[]={ 7, 2, 3, 0, 5, 10, 3, 12, 18 };
	int n=sizeof(a)/sizeof(a[0]);
	buildsparsetable(a,n);
	cout<<"Minimum of (0, 2) is " << query(0, 2) << endl; 
    cout<<"Minimum of (1, 3) is " << query(1, 3) << endl; 
    cout<<"Minimum of (4, 5) is " << query(4, 5) << endl;
	cout<<endl;
    return 0;
}
