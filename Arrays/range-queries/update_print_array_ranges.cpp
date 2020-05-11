#include <iostream>
#include<vector>
using namespace std;

vector<int> initialize_array(vector<int> &a){
	int n=a.size();
	vector<int> D(n+1);
	D[0]=a[0];
	D[n]=0;
	for(int i=1;i<n;i++){
		D[i]=a[i]-a[i-1];
	}
	return D;
}

void update(vector<int> &d, int l, int r, int x){
	d[l]+=x;
	d[r+1]-=x;
}

void print(vector<int> &a, vector<int> &d){
	for(int i=0;i<a.size();i++){
		if(i==0){
			a[i]=d[i];
		}
		else{
			a[i]=d[i]+a[i-1];
		}
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main() 
{
	vector<int> a{ 10, 5, 20, 40 };
	vector<int> d=initialize_array(a);
	update(d,0,1,10);
	print(a,d);
	update(d,1,3,20);
	update(d,2,2,30);
	print(a,d);
	cout<<endl;
    return 0;
}