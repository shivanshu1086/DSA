#include <iostream>
#include<string>
using namespace std;

void rev(int *a, int start, int end){
	while(start<end){
		swap(a[start],a[end]);
		start++;
		end--;
	}
}
void reverserotation(int *a, int n, int d){
	rev(a,0,n-1);
	rev(a,0,d-1);
	rev(a,d,n-1);
}

int main() 
{ 
	int a[]={5, 6, 1, 2, 3, 4};
	int n=sizeof(a)/sizeof(int);
	int d=2;
	reverserotation(a,n,d);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
    return 0;
} 
