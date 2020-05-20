#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <map>
using namespace std;

void max_continuous_sum_except_certain_ele(int *a, int n, int *b, int m){
    sort(b,b+m);
    int max_so_far=INT_MIN;
    int cur_max=0;
    for(int i=0;i<n;i++){
        if(binary_search(b,b+m,a[i])){
            cur_max=0;
            continue;
        }
        cur_max=max(cur_max,cur_max+a[i]);
        max_so_far=max(max_so_far,cur_max);
    }
    cout<<max_so_far;
}

int main()
{
    int a[] ={3, 4, 5, -4, 6};
    int n=sizeof(a)/sizeof(a[0]);
    int b[]={1,8,5};
    int m=sizeof(b)/sizeof(b[0]);
    max_continuous_sum_except_certain_ele(a,n,b,m);
	cout<<endl;
    return 0;
}
