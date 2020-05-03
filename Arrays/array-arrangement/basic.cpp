#include <iostream>
#include<string>
using namespace std;

void rearrange(int *a, int n){
	for(int i=0;i<n;i++){
		if(a[i]!=-1 && a[i]!=i){
			int x=a[i];
			while(a[x]!=-1 && a[x]!=x){
				int y=a[x];
				a[x]=x;
				x=y;
			}
			a[x]=x;
			if(a[i]!=i){
				a[i]=-1;
			}
		}
	}
}

int main() 
{
	int a[]={-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
	int n=sizeof(a)/sizeof(int);
	rearrange(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
    return 0;
}
