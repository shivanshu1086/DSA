#include <iostream>
#include<string>
using namespace std;

bool pairInSortedRotated(int *a, int n, int sum){
	int i;
	for(i=0;i<n-1;i++)
		if(a[i]>a[i+1])
			break;
	int l=(i+1)%n;//l is smallest element
	int r=i;//r is now largest element
	while(l!=r){
		if(a[l]+a[r]==sum){
			return true;
		}
		if(a[l]+a[r]<sum){
			l=(l+1)%n;//l ko ek aage badhaya i.e. second smallest
		}
		else{
			r=(n+r-1)%n;//r ko ek aage badhaya i.e second largest
		}
	}
	return false;
}


int main() 
{ 
    int n;
    cin>>n;
    int a[n]; 
    int sum;
    cin>>sum; 
    if (pairInSortedRotated(a, n, sum)) 
        cout << "Found"; 
    else
        cout << "Not found"; 
	cout<<endl;
    return 0; 
} 
