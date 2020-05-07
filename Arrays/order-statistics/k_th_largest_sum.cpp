#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<climits>
#include<vector>
#include<set>
#include<queue>
using namespace std;

int k_th_largest_sum(int *a, int n, int k){
	int sum[n+1];
	sum[0]=0;
	sum[1]=a[0];
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+a[i-1];
	}
	//priority queue of min-heap
	priority_queue<int, vector<int>, greater<int> > mp;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int x=sum[j]-sum[i-1];
			if(mp.size()<k){
				mp.push(x);
			}
			else{
				if(mp.top()<x){
					mp.pop();
					mp.push(x);
				}
			}
		}
	}
	return mp.top();
}

int main() 
{
	int a[]={ 10, -10, 20, -40 };
	int n=sizeof(a)/sizeof(a[0]);
	cout<<k_th_largest_sum(a,n,6);
	cout<<endl;
    return 0;
}
