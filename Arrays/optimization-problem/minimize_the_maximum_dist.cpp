#include <iostream>
#include<vector>
using namespace std;

void minimize_the_maximum_distance(int *a, int n, int k){
    if(n==1){
        return;
    }
    sort(a,a+n);
    int ans=a[n-1]-a[0];//initialize the ans
    int small=a[0]+k;
    int big=a[n-1]-k;
    if(small>big){
        swap(small,big);
    }
    //traverse rest of the elements
    for(int i=1;i<n-1;i++){
        int subtract=a[i]-k;
        int add=a[i]+k;
        if(subtract>=small || add<=big){
            continue;
        }

        //greedy approach
        if(big-subtract<=add-small){
            small=subtract;
        }
        else{
            big=add;
        }
    }
    cout<< min(ans,big-small);
}


int main()
{
    int a[]={1, 10, 14, 14, 14, 15};
    int n=sizeof(a)/sizeof(a[0]);
    minimize_the_maximum_distance(a,n,3);
	cout<<endl;
    return 0;
}