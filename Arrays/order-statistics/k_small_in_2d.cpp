#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<climits>
#include<vector>
#include<set>
using namespace std;

class heapNode{
public:
	int val;
	int r;
	int c;
};

void heapify(heapNode h[], int i, int heapsize){
	int l=i*2+1;
	int r=i*2+2;
	int parent=i;
	if(l<heapsize && h[l].val<h[parent].val){
		parent=l;
	}
	if(r<heapsize && h[r].val<h[parent].val){
		parent=r;
	}
	if(i!=parent){
		swap(h[i],h[parent]);
		heapify(h,parent,heapsize);
	}
}

void buildHeap(heapNode h[], int n){
	int i=(n-1)/2;
	while(i>=0){
		heapify(h,i,n);
		i--;
	}
}

int kthSmallest(int a[4][4], int n, int k){
	if(k<=0 && k>n*n){
		return INT_MAX;
	}
	heapNode h[n];
	for(int i=0;i<n;i++){
		h[i] =  {a[0][i], 0, i};
	}
	buildHeap(h,n);

	heapNode h1;
	for(int i=0;i<k;i++){
		h1=h[0];
		int nextval;
		if(h1.r<n-1){
			nextval=a[h1.r+1][h1.c];
		}
		else{
			nextval=INT_MAX;
		}
		h[0]= {nextval,h1.r+1,h1.c};
		heapify(h,0,n);
	}
	return h1.val;
}


int main() 
{
	int a[4][4] = { {10, 20, 30, 40}, 
                    {15, 25, 35, 45}, 
                    {25, 29, 37, 48}, 
                    {32, 33, 39, 50}, 
                  }; 
	cout << "7th smallest element is " << kthSmallest(a, 4, 7);
	cout<<endl;
    return 0;
}
