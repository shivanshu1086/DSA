#include <iostream>
#include<string>
using namespace std;

void copyarray(int *a, int n, int *temp){
	for(int i=0;i<n;i++){
		temp[i]=temp[i+n]=a[i];
	}
}

void rotatearray(int *a, int n, int k, int *temp){
	int startingpos=k%n;
	for(int i=startingpos;i<startingpos+n;i++){
		cout<<temp[i]<<" ";
	}
	cout<<endl;
}
void leftRotate(int *a, int n, int k)//space optimization tech
{ 
    for (int i = k; i < k + n; i++) 
        cout << a[i%n] << " ";
	cout<<endl; 
}
int main() 
{ 
	int a[]={15, 18, 2, 3, 6, 12};
	int n=sizeof(a)/sizeof(int);
	int temp[2*n];
	copyarray(a,n,temp);
	int k=2;
	rotatearray(a,n,k,temp);
	k=4;
	rotatearray(a,n,k,temp);
	k=1110;
	rotatearray(a,n,k,temp);
	cout<<endl<<endl;
	k=2;
	leftRotate(a,n,k);
	k=4;
	leftRotate(a,n,k);
	k=1110;
	leftRotate(a,n,k);
	cout<<endl;
    return 0;
} 
