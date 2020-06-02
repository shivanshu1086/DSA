#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void lexicographic_order(string *a, int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int main()
{
    int n;cin>>n;
    string a[n];
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        a[i]=to_string(temp);
    }
    lexicographic_order(a,n);
    return 0;
}
