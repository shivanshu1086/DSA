//Another approach
/*Let an array be {1, 4, 45, 6, 10, -8} and sum to find be 16

After sorting the array
A = {-8, 1, 4, 6, 10, 45}

Now, increment ‘l’ when the sum of the pair is less than the required sum and decrement ‘r’ when the sum of the pair is more than the required sum.
This is because when the sum is less than the required sum then to get the number which could increase the sum of pair, start moving from left to right(also sort the array) thus “l++” and vice versa.

Initialize l = 0, r = 5
A[l] + A[r] ( -8 + 45) > 16 => decrement r. Now r = 4
A[l] + A[r] ( -8 + 10) increment l. Now l = 1
A[l] + A[r] ( 1 + 10) increment l. Now l = 2
A[l] + A[r] ( 4 + 10) increment l. Now l = 3
A[l] + A[r] ( 6 + 10) == 16 => Found candidates (return 1)

*/
#include <iostream>
#include<string>
using namespace std;

bool pair_for_sum(int *a, int n, int sum, int i){
	if(i>=n-1){
		return false;
	}
	int ele=a[i];
	for(int j=0;j<n;j++){
		if(a[j]+ele==sum){
			return true;
		}
	}
	return pair_for_sum(a,n,sum,i+1);
}

int main()
{
	int n;
	cin>>n;
	int a[100];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int sum;
	cin>>sum;
	cout<<boolalpha<<pair_for_sum(a,n,sum,0);
	cout<<endl;
    return 0;
}
