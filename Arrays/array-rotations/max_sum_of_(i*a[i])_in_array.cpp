#include <iostream>
#include<string>
using namespace std;

void swappy(int *a, int start, int end){
		while(start<end){
			swap(a[start],a[end]);
			start++;
			end--;
		}
}

void rotate(int *a, int n, int d){
	swappy(a,0,d-1);
	swappy(a,d,n-1);
	swappy(a,0,n-1);
}

int largest_sum(int *a, int n, int d){
		rotate(a,n,d);
		int sum=0;
		for(int i=0;i<n;i++){
			sum=sum+(i*a[i]);
		}
		return sum;
}



int main() 
{ 
    int n;
    cin>>n;
    int a[n];
	int largest=INT_MIN;
	int d=INT_MIN;
	for(int i=0;i<n;i++){
		int temp;cin>>temp;
		if(temp>largest){
			largest=temp;
			d=i;//largest element
		}
		a[i]=temp;
	}
    cout<<largest_sum(a,n,d+1);
	cout<<endl;
    return 0; 
} 
