#include <iostream>
#include<string>
using namespace std;

int g_c_d(int a, int b){
	if(b==0)
		return a;
	else
		return g_c_d(b,a%b);
}

void leftrotation(int *a, int d, int n){
	int gcd=g_c_d(d,n);
	for(int q=0;q<gcd;q++){
		int j=q;
		int temp=a[q];
		while (1) { 
            int k = j + d; 
            if (k >= n) 
                k = k - n; 
  
            if (k == q) 
                break; 
  
            a[j] = a[k]; 
            j = k; 
        } 
        a[j] = temp; 
	}
}

int main()
{
	int n;
	cin>>n;
	int a[100];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int size;
	cin>>size;
	leftrotation(a,size,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
    return 0;
}
