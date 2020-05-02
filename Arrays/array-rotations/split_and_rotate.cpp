#include <iostream>
#include<string>
using namespace std;

void rotate(int *a, int start, int end){
	while(start<end){
		swap(a[start],a[end]);
		start++;
		end--;
	}
}

void split(int *a, int n, int k){
	rotate(a,0,n);
	rotate(a,0,n-k);
	rotate(a,n-k+1,n);
}

void splitArr(int *a, int length, int rotation) 
{ 
    int tmp[length * 2]; 
  
    for(int i = 0; i < length; i++) 
    { 
        tmp[i]=tmp[i+length]=a[i]; 
    } 
  
    for(int i = rotation; i < rotation + length; i++) 
    { 
        a[i - rotation] = tmp[i];//filling the array
    } 
}

int main() 
{
	int a[]={ 1, 2, 3, 4, 5 };
	int n=sizeof(a)/sizeof(int);
	// split(a,n-1,2);
	splitArr(a,n,2);//second array of size twice
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
    return 0;
}
