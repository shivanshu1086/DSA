#include <iostream>
#include <map>
#include <cmath>

using namespace std;

void minimun_increment_by_k(int *a, int n, int k){
    int max=*max_element(a,a+n);
    int res=0;
    for(int i=0;i<n;i++){
        if((max-a[i])%k!=0){
            cout<<"0";
            return;
        }
        else{
            res+=(max-a[i])/k;
        }
    }
    cout<<res;
}

int main()
{
    int a[] = { 21, 33, 9, 45, 63 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    int k = 6;
    minimun_increment_by_k(a,n,k);
	cout<<endl;
    return 0;
}
