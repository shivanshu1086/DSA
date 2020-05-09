#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <queue>
#include<vector>
using namespace std;

int preproc[100];
int orig_arr[1000];
int blk_size;

//update value
void update(int pos, int val){
	int blockNumber=pos/blk_size;
	preproc[blockNumber]=preproc[blockNumber]+val-orig_arr[pos];
	orig_arr[pos]=val;
}

int query(int l, int r){
	int sum=0;
	while(l<r && l%blk_size!=0 && l!=0){
		// l value is between some blocks not any starting block and l is not 0;
		sum+=orig_arr[l];
		l++;//it takes extra elements on the left.
	}

	//now overlapped block sum
	while(l+blk_size<=r){
		sum+=preproc[l/blk_size];
		l+=blk_size;
	}
	//right me extra block if left

	while(l<=r){
		sum+=orig_arr[l];
		l++;
	}

	return sum;
}

void preprocess(int a[10], int n){
	int blk_ptr=-1;
	blk_size=sqrt(n);
	for(int i=0;i<n;i++){
		orig_arr[i]=a[i];
		if(i%blk_size==0){
			blk_ptr++;
		}
		preproc[blk_ptr]+=a[i];
	}
}

int main() 
{
	int a[]={1, 5, 2, 4, 6, 1, 3, 5, 7, 10};
	int n=sizeof(a)/sizeof(a[0]);
	preprocess(a,n);
	cout << "query(3,8) : " << query(3, 8) << endl;
	cout << "query(3,8) : " << query(1, 6) << endl;
	cout << "query(3,8) : " << query(2, 4) << endl;
	update(8,0);
	cout << "query(3,8) : " << query(8, 8) << endl;
	cout<<endl;
    return 0;
}
