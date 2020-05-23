#include <iostream>
#include <map>
#include <cmath>

using namespace std;

bool subarray_ispart_of_array(int *a, int m, int *b, int n){
    sort(a,a+m);
    sort(b,b+n);
    int i=0;
    int j=0;
    while(i<m && j<n){
        if(a[j]<b[i]){
            j++;
        }

        else if(a[j]==b[i]){
            i++,j++;
        }

        else if(a[j]>b[i]){
            return 0;
        }
    }
    return  (i < n)? false : true;
}

int main()
{
    int a[] = {11, 1, 13, 21, 3, 7};
    int b[]= {11, 3, 7, 1};
    int m=sizeof(a)/sizeof(a[0]);
    int n=sizeof(b)/sizeof(b[0]);
    cout<<boolalpha<<subarray_ispart_of_array(a,m,b,n);
	cout<<endl;
    return 0;
}
