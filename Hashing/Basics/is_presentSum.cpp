#include <iostream>
#include <unordered_set>
using namespace std;

void is_presentSum(int *a, int n, int x){
    unordered_set<int> set;
    for(int i=0;i<n;i++){
        int temp = x-a[i];
        if(set.find(temp)!=set.end()){
            cout<<"Pair with given sum "<<x<<" is ("<<a[i]<<","<<temp<<")";
            return;
        }
        set.insert(a[i]);
    }
}


int main(){
    int a[] = { 1, 4, 45, 6, 10, 8 };
    int n = sizeof(a)/sizeof(a[0]);
    int x = 16;

    is_presentSum(a,n,x);
    cout<<endl;
    return 0;
}