#include <iostream>
#include<string>
using namespace std;



void swapy(int *a, int fi, int si, int d){
	int temp;
	for(int i=0;i<d;i++){
		swap(a[fi+i],a[si+i]);
	}
}

void leftrotation(int *a, int d, int n){
	if(d==0||d==n){
		return;
	}
	if(n-d==d){
		swapy(a,0,n-d,d);//here d is the number of swapping
		return;
	}
	if(d<n-d){
		swapy(a,0,n-d,d);
		leftrotation(a,d,n-d);
	}
	else{
		swapy(a,0,d,n-d);
		leftrotation(a+n-d,2*d-n,d);
	}
}

int main()
{
	int n;
	cin>>n;
	int a[100];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int size;
	cin>>size;
	leftrotation(a,size,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
    return 0;
}
