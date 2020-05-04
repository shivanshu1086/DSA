#include <iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;
//It is known as lomuto partition
void even_then_odd(int *a, int n){
	int j=-1;
	for(int i=0;i<n;i++){
		if(a[i]%2==0){
			j++;
			swap(a[i],a[j]);
		}
	}
}//but it distort the order


int main() 
{
	int a[]={ 1, 3, 2, 4, 7, 6, 9, 10 };
	int n=sizeof(a)/sizeof(int);
	even_then_odd(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
    return 0;
}
