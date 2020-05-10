#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>
#include<vector>
using namespace std;

int lookup[500][500];

class pairs{
public:
	int from;
	int to;
};

void preprocessing(int *a, int n){
	for(int i=0;i<n;i++){
		lookup[i][i]=a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[j]<lookup[i][j-1]){
				lookup[i][j]=a[j];
			}
			else{
				lookup[i][j]=lookup[i][j-1];
			}
		}
	}
}

void rangeminquery(int *a, pairs *q, int n, int m){
	for(int i=0;i<m;i++){
		int from=q[i].from;
		int to=q[i].to;
		cout<<"Minimum of [" << from << ", "<< to << "] is "  << lookup[from][to] << endl;
	}
}//this takes O(n^2) time in preprocessing and space

//Square root decomposition approach
void preprocessing2(int *a, pairs *q, int n, int m){
	int lookup2[500];
	for(int i=0;i<500;i++){
		lookup2[i]=INT_MAX;
	}
	int j=(int)(log2(n));
	int curblk=-1;
	for(int i=0;i<n;i++){
		if(i%j==0){
			curblk++;
		}
		lookup2[curblk]=min(lookup2[curblk],a[i]);
	}
	for(int k=0;k<m;k++){
		int from=q[k].from;
		int to=q[k].to;
		if(from-to>=j){
			cout<<min(lookup2[from%j],lookup2[to%j])<<endl;
		}
		else{
			int curmin=a[from];
			for(int p=from+1;p<=to;p++){
				curmin=min(curmin,a[p]);
			}
			cout<<curmin<<endl;
		}
	}
}//it takes O(n*n^1/2) time and space os O(n^1/2).

// Sparse table implementation
int lookup3[500][500];
void preprocessing3(int *a, int n){
	for(int i=0;i<n;i++){
		lookup3[i][0]=a[i];
	}

	//further filling
	for(int j=1;(1<<j)<=n;j++){//only (int)(log2(n)) column
		for(int i=0;(i+(1<<j)-1)<n;i++){
			if(lookup3[i][j-1]<lookup3[i+(1<<(j-1))][j-1]){
				lookup3[i][j]=lookup3[i][j-1];
			}
			else{
				lookup3[i][j]=lookup3[i+(1<<(j-1))][j-1];
			}
		}
	}

}

void rangeminquery2(int *a, pairs *q, int n, int m){
	for(int i=0;i<m;i++){
		int from=q[i].from;
		int to=q[i].to;

		int j=(int)log2(to-from+1);
		if(lookup3[from][j]<lookup3[to-(1<<j)+1][j]){
			cout<< lookup3[from][j]<<endl;
		}
		else{
			cout<<lookup3[to-(1<<j)+1][j]<<endl;
		}
	}
}

int main() 
{
	int a[]={ 7, 2, 3, 0, 5, 10, 3, 12, 18 };
	int n=sizeof(a)/sizeof(a[0]);
	pairs q[]= {{0, 4}, {4, 7}, {7, 8},{5,5}};
	int m=sizeof(q)/sizeof(q[0]);
	// preprocessing(a,n);
	// rangeminquery(a,q,n,m);
	// preprocessing2(a,q,n,m);
	preprocessing3(a,n);
	rangeminquery2(a,q,n,m);
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<=(int)(log2(n));j++){
	// 		cout<<lookup3[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<(int)(log2(n));
	cout<<endl;
    return 0;
}
