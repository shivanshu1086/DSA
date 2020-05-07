#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<climits>
#include<vector>
#include<set>
#include<queue>
using namespace std;

void k_smallest_orderwise(int *a, int n, int k){
	for(int i=k;i<n;i++){
		//get the max of the range 0-k
		int max=a[k-1];
		int pos=k-1;
		for(int j=k-2;j>=0;j--){
			if(a[j]>max){
				max=a[j];
				pos=j;
			}
		}

		//now check it with the right part elements
		if(max>a[i]){
			int j=pos;
			while(j<k-1){
				a[j]=a[j+1];
				j++;
			}
			//In range 0-k a[k-1] and a[k-2] elements are same so change them
			a[k-1]=a[i];
		}
	}
	//now we have our desired array
		for(int c=0;c<k;c++){
			cout<<a[c]<<" ";
		}
}

int main() 
{
	int a[]={ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
	int n=sizeof(a)/sizeof(a[0]);
	k_smallest_orderwise(a,n,5);
	cout<<endl;
    return 0;
}
