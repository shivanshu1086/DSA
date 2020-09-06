#include <iostream>
#include <queue>
#include <vector>
#define n 4
using namespace std;

vector<int> mergeArray(int a[][n], int k){
    priority_queue<int, vector<int>, greater<int> > minh;
    vector<int> v;

    for(int i=0,j=0;i<n;i++){
        minh.push(a[j][i]);
        minh.push(a[j+1][i]);
        minh.push(a[j+2][i]);
        v.push_back(minh.top());
        minh.pop();
    }
    while(!minh.empty()){
        v.push_back(minh.top());
        minh.pop();
    }
    return v;
}


int main(){
    int arr[][n] =  {{2, 6, 12, 34}, 
                     {1, 9, 20, 1000}, 
                     {23, 34, 90, 2000}}; 
    int k = sizeof(arr)/sizeof(arr[0]);
    vector<int> v = mergeArray(arr,k);
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}