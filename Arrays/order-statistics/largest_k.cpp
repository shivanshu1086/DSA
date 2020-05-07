#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<climits>
#include<vector>
#include<set>
using namespace std;

void maximum(int *a, int n, int k){

	//bubble sort implementation
	if(k<n && k>0){
		for(int i=0;i<k;i++){
		for(int j=0;j<n-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
		cout<<a[n-i-1]<<" ";
		}
	}
	else{
		cout<<"Please choose a different K value";
	}

	//remove duplicates
	/*sort(a,a+n);
	int count=1;
	int check=0;
	for(int i=1;i<=n;i++){
		if(count<4){
			if(check!=a[n-i]){
				cout<<a[n-i]<<" ";
				check=a[n-i];
				count++;
			}
		}
		else{
			break;
		}
	}*/

}

int main() 
{
	int a[]={20, 10, 20, 4, 100};
	int n=sizeof(a)/sizeof(a[0]);
	int k=4;
	maximum(a,n,k);
	cout<<endl;
    return 0;
}
