#include <iostream>
#include<vector>
using namespace std;


void minimum_distance(int *a, int n, int x, int y){
    int p=-1;
    int c_min=INT_MAX;
    for(int i=0;i<n;i++){
        if(a[i]==x||a[i]==y){
            if(p!=-1 && a[i]!=a[p]){//second condition is for both the elements should not be equal
                c_min=min(c_min,i-p);
            }
            p=i;
        }
    }
    if(c_min==INT_MAX){
        cout<<"-1"<<endl;
    }
    else{
        cout<<c_min<<endl;
    }
}


int main()
{
    int a[]={3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3};
    int n=sizeof(a)/sizeof(a[0]);
    minimum_distance(a,n,3,6);
	cout<<endl;
    return 0;
}