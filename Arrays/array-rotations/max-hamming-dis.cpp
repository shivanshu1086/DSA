#include <iostream>
#include<string>
using namespace std;

int hamdis(int *a, int n){
	int temp[2*n];
	for(int i=0;i<n;i++){
		temp[i]=temp[i+n]=a[i];
	}
	int maxhamds=0;
	for(int i=1;i<n;i++){
		int curham=0;
		for(int j=i,k=0;j<(i+n);j++,k++){
			if(temp[j]!=a[k]){
				curham++;
			}
		}
		if(curham==n){
			return n;
		}
		maxhamds=max(maxhamds,curham);
	}
	return maxhamds;
}


int main() 
{
	int a[]={5, 6, 1, 2, 3, 4};
	int n=sizeof(a)/sizeof(int);
	cout<<hamdis(a,n);
	cout<<endl;
    return 0;
}
