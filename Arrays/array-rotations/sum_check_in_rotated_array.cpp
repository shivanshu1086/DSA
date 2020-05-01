#include <iostream>
#include<string>
using namespace std;

int pairInSortedRotated(int *a, int n, int sum){
	int i;
	for(i=0;i<n-1;i++)
		if(a[i]>a[i+1])
			break;
	int l=(i+1)%n;//l is smallest element
	int r=i;//r is now largest element
	int cnt=0;
	while(l!=r){
		if(a[l]+a[r]==sum){
			cnt++;
			if(l==(r+n-1)%n){
				return cnt;
			}
			l=(l+1)%n;
			r=(n+r-1)%n;
		}
		else if(a[l]+a[r]<sum){
			l=(l+1)%n;//l ko ek aage badhaya i.e. second smallest
		}
		else{
			r=(n+r-1)%n;//r ko ek aage badhaya i.e second largest
		}
	}
	return -1;
}


int main() 
{ 
    int n;
    cin>>n;
    int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i]; 
    int sum;
    cin>>sum;
	int ans=pairInSortedRotated(a, n, sum);
	// cout<<ans;
    if (ans>0) 
        cout<<ans<< " Found"; 
    else
        cout << "Not found"; 
	cout<<endl;
    return 0; 
} 
