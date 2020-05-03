#include <iostream>
#include<string>
using namespace std;


void reverse(int *a, int start, int end){
	while(start<end){
		swap(a[start],a[end]);
		start++;
		end--;
	}
}

void reverse_recursive(int *a, int start, int end){
	if(start>=end){
		return;
	}
	swap(a[start],a[end]);
	reverse_recursive(a,start+1,end-1);
}

int main() 
{
	int a[]={-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
	int n=sizeof(a)/sizeof(int);
	// reverse(a,0,n-1);
	// reverse_recursive(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
    return 0;
}
