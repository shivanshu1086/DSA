#include <iostream>
#include<string>
using namespace std;

void rotate(int *a, int start, int end){
	int temp=a[end];
	for(int i=end;i>start;i--){
		a[i]=a[i-1];
	}
	a[start]=temp;
}

int findelement(int *a, int n, int ranges[][2], int index){
	for(int i=0;i<2;i++){
		rotate(a,ranges[i][0],ranges[i][1]);
	}
	return a[index];
}

int findele(int *a, int n, int ranges[][2], int index){
	for(int i=1;i>=0;i--){
		int l=ranges[i][0];
		int r=ranges[i][1];
		if(l<=index && r>=index){
			if(l==index){
				index=r;
			}
			else{
				index--;
			}
		}
	}
	return a[index];
}

int main() 
{
	int a[]={ 1, 2, 3, 4, 5 };
	int n=sizeof(a)/sizeof(int);
	int ranges[][2]={{0,2},{0,3}};
	int index=1;
	// cout<<findelement(a,n,ranges,index)<<endl;//brute force approach
	cout<<findele(a,n,ranges,index);//efficient approach
	cout<<endl;
    return 0;
}
