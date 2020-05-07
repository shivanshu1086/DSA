#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<climits>
#include<vector>
#include<set>
using namespace std;

double mean(int *a, int n){
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
	return (double)sum/(double)n;
}

double median(int *a, int n){
	sort(a,a+n);
	if(n%2!=0){//if it is not even then mid element will be the median
		return (double)a[n/2];
	}
	else{//else mid and mid-1
		return (double)(a[(n-1)/2] + a[n/2])/2.0;
	}
}

int main() 
{
	int a[]={ 1, 3, 4, 2, 7, 5, 8, 6 };
	int n=sizeof(a)/sizeof(a[0]);
	cout<<mean(a,n);
	cout<<endl;
	cout<<median(a,n);
	cout<<endl;
    return 0;
}
