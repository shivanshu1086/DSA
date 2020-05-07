//kadanes algorithm
#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<climits>
#include<vector>
#include<set>
#include<queue>
using namespace std;

void kadanes_extended(int *a, int n, int k){
	for(int c=0;c<k;c++){
		int max_so_far=INT_MIN;
		int max_ending_here=0;
		int start,end,s=0;
		for(int i=0;i<n;i++){
			max_ending_here=max_ending_here+a[i];
			if(max_ending_here>max_so_far){
				max_so_far=max_ending_here;
				start=s;
				end=i;
			}
			if(max_ending_here<0){
				max_ending_here=0;
				s=i+1;
			}
		}
		cout<<"sum "<<(c+1)<<": {"<<max_so_far<<"}. starting from "<<start<<" to "<<end<<endl;
		for(int i=start;i<=end;i++){
			a[i]=INT_MIN;
		}
	}
}

int main() 
{
	int a[]={5, 1, 2, -6, 2, -1, 3, 1};
	int n=sizeof(a)/sizeof(a[0]);
	kadanes_extended(a,n,3);
	cout<<endl;
    return 0;
}
