#include <iostream>
#include<vector>
#include <cmath>
using namespace std;

int checkbit(int *ar, int index){
    return ar[index>>5]&(1<<(index&31));
}

void size_using_bit_manipulation(int *ar, int index){
    ar[index>>5]|=(1<<(index&31));
}


int main()
{
    // int a[]={30, 5, 20, 9};
    // int n=sizeof(a)/sizeof(a[0]);
    int a=2,b=10;
    int size=abs(b-a);
    size=ceil(size/32);
    // int *ar=new int[size];
    int ar[size];
    for(int i=a;i<=b;i++){
        if(i%2==0 || i%5==0){
            size_using_bit_manipulation(ar,i-a);
        }
    }
    for(int i=a;i<=b;i++){
        if(checkbit(ar,i-a)){
            cout<<i<<" ";
        }
    }
	cout<<endl;
    return 0;
}
