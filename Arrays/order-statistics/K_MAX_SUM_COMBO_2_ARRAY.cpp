#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<climits>
#include<vector>
#include<set>
#include<queue>
using namespace std;



void k_max(int *a, int *b, int n, int k){
	priority_queue<int>pq;
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			pq.push(a[i]+b[j]);
		}
	}
	int count=0;
	while(count<k){
		cout<<pq.top()<<" ";
		pq.pop();
		count++;
	}
}


void K_MAX_SUM(int *a, int *b, int n, int k){
	sort(a,a+n);
	sort(b,b+n);
	priority_queue<pair<int,pair<int,int> > > pq;
	set<pair<int,int> > s;

	pq.push(make_pair(a[n-1]+b[n-1],make_pair(n-1,n-1)));

	s.insert(make_pair(n-1,n-1));

	//now get a loop to K
	for(int count=0;count<k;count++){
		pair<int,pair<int,int> > temp=pq.top();
		pq.pop();
		cout<<"("<<a[i]<<","<<b[j]<<")"<<endl;
		int i=temp.second.first;
		int j=temp.second.second;

		int sum=a[i-1]+b[j];
		//set insertion
		pair<int,int> temp1=make_pair(i-1,j);
		if(s.find(temp1)==s.end()){
			pq.push(make_pair(sum,temp1));
			s.insert(temp1);
		}

		sum=a[i]+b[j-1];

		pair<int,int> temp2=make_pair(i,j-1);
		if(s.find(temp2)==s.end()){
			pq.push(make_pair(sum,temp2));
			s.insert(temp2);
		}
	}
}

int main() 
{
	int a[]={ 1, 4, 2, 3 };
	int n=sizeof(a)/sizeof(a[0]);
	int b[]={ 2, 5, 1, 6 };
	K_MAX_SUM(a,b,n,4);
	// k_max(a,b,n,4);
	cout<<endl;
    return 0;
}
