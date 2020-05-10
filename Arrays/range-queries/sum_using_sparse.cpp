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

void buildsparsetable(int *a, int n){
	for(int i=0;i<n;i++){
		lookup[i][0]=a[i];
	}//for gap=0;

	//further updation
	for(int j=1;j<=n;j++){
		for(int i=0;i<=n-(1<<j);i++){
			lookup[i][j]=lookup[i][j-1]+lookup[i+(1<<(j-1))][j-1];
		}
	}
}

int query(int l, int r){
	int ans=0;
	for(int j=16;j>=0;j--){
		if(l+(1<<j)-1<=r){
			ans+=lookup[l][j];
			l+=1<<j;
		}
	}
	return ans;
}

int main() 
{
	int a[]={ 7, 2, 3, 0, 5, 10, 3, 12, 18 };
	int n=sizeof(a)/sizeof(a[0]);
	buildsparsetable(a, n); 
    cout << query(0, 5) << endl; 
    cout << query(3, 5) << endl; 
    cout << query(2, 4) << endl; 
	cout<<endl;
    return 0;
}
