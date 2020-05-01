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

int largest_sum(int *a, int n, int d){//only when array is sorted and rotated
			rotate(a,n,d);
			int sum=0;
			for(int i=0;i<n;i++){
				sum=sum+(i*a[i]);
			}
		return sum;//O(n)
}

int easier_approach(int *a, int n){
	int sum_of_array=0;
	int rotated_sum=0;
	for(int i=0;i<n;i++){
		sum_of_array=sum_of_array+a[i];
		rotated_sum=rotated_sum+(i*a[i]);
	}
	int finalsum=rotated_sum;
	for(int i=1;i<n;i++){//starting from second
		rotated_sum=rotated_sum+sum_of_array-(n*a[n-i]);//As rotated_sum(i)-rotated_sum(i-1)=sum_of_array-n*a[n-i];
		if(rotated_sum>finalsum){
			finalsum=rotated_sum;
		}
	}
	return finalsum;//O(n)
}

int all_rotations(int *a, int n){
	int finalsum=0;
	for(int i=0;i<n;i++){
		int cur_sum=0;
		for(int j=0;j<n;j++){
			cur_sum=cur_sum+(j*a[(i+j)%n]);//starting from one and then further till last sum of every rotation.
		}
		finalsum=max(cur_sum,finalsum);
	}
	return finalsum;//O(n^2)
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
			d=i;
		}
		a[i]=temp;
	}
    cout<<largest_sum(a,n,d+1)<<endl;
	cout<<easier_approach(a,n)<<endl;
	cout<<all_rotations(a,n);
	cout<<endl;
    return 0; 
} 
