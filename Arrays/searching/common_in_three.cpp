#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <unordered_set>
using namespace std;



int main()
{
    int a[] ={1, 5, 5};
    int b[]={3, 4, 5, 5, 10};
    int c[]={5, 5, 10, 20};
    int m=sizeof(a)/sizeof(a[0]);
    int n=sizeof(b)/sizeof(b[0]);
    int o=sizeof(c)/sizeof(c[0]);
    int i=0,j=0;
    int k=0;
    // int uni[min(m,n)];
    while(i<m && j<n){
        if(a[i]==b[j] && b[j]==c[k]){
            cout<<a[i]<<" ";
            i++;
            j++;
            k++;
        }
        else if(a[i]<b[j]){
            i++;
        }
        else if(b[j]<c[k]){
            j++;
        }
        else{
            k++;
        }
    }
    // k--;
    // i=0;
    // while(k>=0 && i<o-1){
    //     if(uni[k]==c[i]){
    //         cout<<uni[k--]<<" ";
    //         i=0;
    //     }
    //     i++;
    // }
	cout<<endl;
    return 0;
}
