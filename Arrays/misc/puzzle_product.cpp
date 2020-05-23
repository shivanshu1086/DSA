#include <iostream>
#include <map>
#include <cmath>

using namespace std;

void puzzle_product(int *a, int n){
    int prod[n];
    int i=0;
    int ans=1;
    while(i<n){
        for(int j=0;j<n;j++){
            if(j==i){
                continue;
            }
            ans*=a[j];
        }
        prod[i]=ans;
        i++;
        ans=1;
    }

    //print the desired array
    for(int i=0;i<n;i++){
        cout<<prod[i]<<" ";
    }
}

int main()
{
    int a[] = { 10, 3, 5, 6, 2 };
    int n=sizeof(a)/sizeof(a[0]);
    puzzle_product(a,n);
	cout<<endl;
    return 0;
}
