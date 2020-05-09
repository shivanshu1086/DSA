#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <queue>
#include<vector>
using namespace std;

//naive solution
class pairs{
	public:
	int from;
	int to;
};

void sum_of_query(int *a, pairs *q, int n, int k){
	for(int i=0;i<k;i++){
		int from=q[i].from;
		int to=q[i].to;
		int sum=0;
		for(int j=from;j<=to;j++){
			sum+=a[j];
		}
		cout<<sum<<endl;
	}
}

//MO's algorithm
int block;

bool compare(pairs q1, pairs q2){
	if(q1.from/block!=q2.from/block){
		return q1.from/block<q2.from/block;
	}
	return q1.to<q2.to;//if from value are equal in both
}

void mo_algo(int *a, pairs *q, int n, int m){
	block=(int)sqrt(n);
	sort(q,q+m,compare);
	int curFrom=0;
	int curTo=0;
	int curSum=0;
	//traversing through all queries
	for(int i=0;i<m;i++){
		int from=q[i].from;
		int to=q[i].to;

		//remove
		while(curFrom<from){
			curSum-=a[curFrom];
			curFrom++;
		}
		//add elements
		while(curFrom>from){
			curSum+=a[curFrom-1];
			curFrom--;
		}
		while(curTo<=to){
			curSum+=a[curTo];
			curTo++;
		}
		//remove
		while(curTo>to+1){
			curSum-=a[curTo-1];
			curTo--;
		}
		cout<<"["<<from<<","<<to<<"]"<<": "<<curSum<<endl;
	}
}

int main() 
{
	int a[]={1, 1, 2, 1, 3, 4, 5, 2, 8};
	int n=sizeof(a)/sizeof(a[0]);
	pairs query[] = {{0, 4}, {1, 3}, {2, 4}};
	int k=sizeof(query)/sizeof(query[0]);
	// sum_of_query(a,query,n,k);
	mo_algo(a,query,n,k);
	cout<<endl;
    return 0;
}
