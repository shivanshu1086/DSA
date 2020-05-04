#include <iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

void reorder_array(int *a, int n, int *index){//simple way using temp array
	int temp[n];
	for(int i=0;i<n;i++){
		temp[index[i]]=a[i];
	}
	for(int i=0;i<n;i++){
		cout<<temp[i]<<" ";
	}
}
//using no extra space
void reorder(int *a, int *index, int n){
	for(int i=0;i<n;i++){
		while(index[i]!=i){
			// swap the positions
			int oldE=a[index[i]];
			int oldI=index[index[i]];
			//right to left
			a[index[i]]=a[i];
			index[index[i]]=index[i];
			//left to right
			a[i]=oldE;
			index[i]=oldI;
		}
	}
}
int main() 
{
	int a[]={50,40,70,60,90};
	int n=sizeof(a)/sizeof(int);
	int index[]={3,0,4,1,2};
	// reorder_array(a,n,index);
	reorder(a,index,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
    return 0;
}
