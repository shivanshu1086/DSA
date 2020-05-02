#include <iostream>
#include<string>
using namespace std;

void reverserotate(int *a, int start, int end){
	while(start<end){
		swap(a[start], a[end]);
		start++;
		end--;
	}
}

void rightrotate(int *a, int d, int n){
	reverserotate(a,0,n-1);
	reverserotate(a,0,d-1);
	reverserotate(a,d,n-1);
}

void leftrotate(int *a, int d, int n){
	reverserotate(a,0,d-1);
	reverserotate(a,d,n-1);
	reverserotate(a,0,n-1);
}

void printsum(int *a, int l, int r){
	int sum=0;
	for(int i=l;i<=r;i++){
		sum+=a[i];
	}
	cout<<sum<<endl;
}

void query(int *a, int n, int q, int x, int l=0, int r=0){
	if(q==1){
		rightrotate(a,x,n);
	}
	else if(q==2){
		leftrotate(a,x,n);
	}
	else{
		printsum(a,l,r);
	}
}

//second method

void q1(int *rotate, int x, int n){
	(*rotate)=((*rotate)-x)%n;
}
void q2(int *rotate, int x, int n){
	(*rotate)=((*rotate)+x)%n;
}
void q3(int rotate, int l, int r, int *presum, int n){
	l = (l + rotate + n) % n; 
    r = (r + rotate + n) % n;
	if (l <= r)  
        cout << (presum[r + 1] - presum[l]) << endl;
    else 
        cout << (presum[n] + presum[r + 1] - presum[l])<< endl;   
}
void wrapper(int *a, int n){
	int presum[n+1];
	presum[0]=0;
	for(int i=1;i<=n;i++){
		presum[i]=presum[i-1]+a[i-1];
	}
	int rotate=0;
	q1(&rotate,3,n);
	q3(rotate,0,2,presum,n);
	q2(&rotate,1,n);
	q3(rotate,1,4,presum,n);
}

int main() 
{
	int a[]={ 1, 2, 3, 4, 5 };
	int n=sizeof(a)/sizeof(int);
	// query(a,n,1,3);
	// query(a,n,3,0,0,2);
	// query(a,n,2,1);
	// query(a,n,3,0,1,4);
	wrapper(a, n);
	cout<<endl;
    return 0;
}
 