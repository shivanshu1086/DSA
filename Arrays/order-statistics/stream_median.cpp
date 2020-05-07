#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<climits>
#include<vector>
#include<set>
#include<queue>
using namespace std;

void stream_median(int *v, int n){
	// sort(v.begin(),v.end());
	for(int j=1;j<=n;j++){
		int temp[j];
		for(int k=0;k<j;k++){
			temp[k]=v[k];
		}
		sort(temp,temp+j);
		int i=j;
		if(i%2!=0){
			cout<<temp[i/2];
			cout<<endl;
		}
		else{
			cout<<(temp[i/2]+temp[(i-1)/2])/2.0;
			cout<<endl;
		}
	}
}//O(n) way

//priority queue O(1) way;
void one_by_one(int *a, int n){
	priority_queue<double>s;//max heap
	//min heap
	priority_queue<double,vector<double>,greater<double> >g;

	s.push(a[0]);
	double med=a[0];
	cout<<med<<endl;

	for(int i=1;i<n;i++){
		double x=a[i];
		//case 1
		if(s.size()>g.size()){
			if(x<med){
				g.push(s.top());
				s.pop();
				s.push(x);
			}
			else{
				g.push(x);
			}
			med=(g.top()+s.top())/2.0;
		}
		//case 2
		else if(s.size()==g.size()){
			if(x<med){
				s.push(x);
				med=(double)s.top();
			}
			else{
				g.push(x);
				med=(double)g.top();
			}
		}
		//case 3
		else{
			if(x<med){
				s.push(x);
			}
			else{
				s.push(g.top());
				g.pop();
				g.push(x);
			}
			med=(s.top()+g.top())/2.0;
		}
		cout<<med<<endl;
	}
}


int main() 
{
	int a[]={ 1, 3, 4, 2, 7, 5, 8, 6 };
	int n=sizeof(a)/sizeof(a[0]);
	stream_median(a,n);
	// one_by_one(a,n);
	cout<<endl;
    return 0;
}
