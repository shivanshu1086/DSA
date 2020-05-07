#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<climits>
#include<vector>
#include<set>
#include<queue>
using namespace std;

int second_largest(int *a, int n){
	int first=a[0];
	int second=INT_MIN;
	for(int i=1;i<n;i++){
		if(a[i]>first){
			second=first;
			first=a[i];
		}
		else if(a[i]>second && a[i]!=first){
			second=a[i];
		}
	}
	if(first!=second){
		return second;
	}
	else{
		return INT_MAX;
	}
}


int main() 
{
	int a[]={10, 10, 10};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<second_largest(a,n);
	cout<<endl;
    return 0;
}
