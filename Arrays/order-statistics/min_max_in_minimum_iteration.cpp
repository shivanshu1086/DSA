#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <queue>
#include<vector>
using namespace std;

class pairs{
public:
 int max;
 int min;
};

pairs getMinMax(int *a, int n){
	pairs min_max;
	int i;

	if(n==1){
		min_max.min=a[0];
		min_max.max=a[0];
		return min_max;
	}
	//initialize 1st and 2nd element in max and min.
	(a[0]>a[1])?min_max.max=a[0],min_max.min=a[1]:min_max.min=a[0],min_max.max=a[1];

	// for rest of the elements
	for(i=2;i<n;i++){
		if(a[i]>min_max.max){
			min_max.max=a[i];
		}
		else if(a[i]<min_max.min){
			min_max.min=a[i];
		}
	}
	return min_max;
}

pairs midMethod(int *a, int low, int high){
	pairs min_max, mml, mmr;
	int mid;

	if(low==high){//if one element
		min_max.min=a[0];
		min_max.max=a[0];
		return min_max;
	}

	if(low==high-1){//if two elements
		if(a[low]>a[high]){
			min_max.max=a[low];
			min_max.min=a[high];
			return min_max;
		}
		else{
			min_max.max=a[high];
			min_max.min=a[low];
			return min_max;
		}
	}

	//for more than two
	mid=low+(high-low)/2;
	mml=midMethod(a,low,mid);//it gets minimum and maximum from left part
	mmr=midMethod(a,mid+1,high);//it gets minimum and maximum from right part

	(mml.max>mmr.max)?min_max.max=mml.max:min_max.max=mmr.max;
	(mml.min<mmr.min)?min_max.min=mml.min:min_max.min=mmr.min;
	return min_max;
}

pairs pairMethod(int *a, int n){
	pairs min_max;
	int i;
	(n%2==0)?(a[0]>a[1])?(min_max.max=a[0],min_max.min=a[1]):(min_max.max=a[1],min_max.min=a[0]),i=2:(min_max.min=a[0],min_max.max=a[0]),i=1;

	//pick piars and compare
	while(i<n-1){
		if(a[i]>a[i+1]){
			if(a[i]>min_max.max){
				min_max.max=a[i];
			}
			if(a[i+1]<min_max.min){
				min_max.min=a[i+1];
			}
		}
		else{
			if(a[i+1]>min_max.max){
				min_max.max=a[i+1];
			}
			if(a[i+1]<min_max.min){
				min_max.min=a[i+1];
			}
		}
		i+=2;
	}
	return min_max;
}

int main() 
{
	int a[]={5, 5, 10, 100, 10, 5};
	int n=sizeof(a)/sizeof(a[0]);
	// pairs min_max=getMinMax(a,n);
	// pairs min_max=midMethod(a,0,n-1);
	pairs min_max =pairMethod(a,n);
	cout<<min_max.max<<endl;
	cout<<min_max.min;
	cout<<endl;
    return 0;
}
