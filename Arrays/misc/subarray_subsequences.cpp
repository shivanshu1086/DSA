#include <iostream>
#include <map>
#include <cmath>

using namespace std;

void subArrays(int *a, int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout<<a[k]<<" ";
            }
            cout<<endl;
        }
    }
}

void subsequences(int *a, int n){
    unsigned int total_seq=pow(2,n);

    for(int count=1;count<total_seq;count++){
        for(int j=0;j<n;j++){
            if(count & (1<<j)){
                cout<<a[j]<<" ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    int a[] = {1,2,3,4};
    int n=sizeof(a)/sizeof(a[0]);
    subArrays(a,n);
    cout<<endl;
    subsequences(a,n);
	cout<<endl;
    return 0;
}
