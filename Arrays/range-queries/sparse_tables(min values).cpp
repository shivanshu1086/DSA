#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <queue>
#include<vector>
using namespace std;

int lookup[500][500];

/* matrix in this case will be
	7 2 0 0
	2 2 0 0 
	3 0 0 -
	0 0 0 -
	5 5 3 -
	10 3 3 -
	3 3 - -
	12 12 - -
	18 - - -
*/

void buildsparsetable(int *a, int n){
	for(int i=0;i<n;i++){
		lookup[i][0]=a[i];//minimum values of interval 1.
	}//copy all the elements in first column as they are minimum when range is (l,l)

	//further updation
	for(int j=1;(1<<j)<=n;j++){//(1<<j) is the power of 2 condition check as we need 3 more column other than 0th(n==8>>2^3).
		//compare minimum values of interval 2^j(2,4,8).
		for(int i=0;(i+(1<<j)-1)<n;i++){//the checking condition is how many times column gets filled. j+1 j+1 ke kitne pair fill honge
			if(lookup[i][j-1]<lookup[i+(1<<(j-1))][j-1]){
				lookup[i][j]=lookup[i][j-1];//lookup[0][1] me [0][0] insert kiya agar [0][0] minimum hai.
			}
			else{
				lookup[i][j]=lookup[i+(1<<(j-1))][j-1];
			}
		}
	}
}

int query(int l, int r){
	int j=(int)log2(r-l+1);//nearest power of 2 in the given range. J gives us in which range we lookup for our answer.

	if(lookup[l][j]<=lookup[r-(1<<j)+1][j]){
		return lookup[l][j];
	}
	else{
		return lookup[r-(1<<j)+1][j];
	}
//returns the minimum in that range
}

int main() 
{
	int a[]={ 7, 2, 3, 0, 5, 10, 3, 12, 18 };
	int n=sizeof(a)/sizeof(a[0]);
	buildsparsetable(a,n);
	cout<<"Minimum of [0, 4] is " << query(0, 4) << endl; 
    cout<<"Minimum of [4, 7] is " << query(4, 7) << endl; 
    cout<<"Minimum of [7, 8] is " << query(7, 8) << endl;
	cout<<endl;
    return 0;
}
