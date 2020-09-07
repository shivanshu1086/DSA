#include <iostream>
#include <queue>

using namespace std;

int minProduct(int *a, int n, int k){
    int res =1;
    priority_queue<int> maxh;
    for(int i=0;i<n;i++){
        maxh.push(a[i]);
        if(maxh.size()>k){
            maxh.pop();
        }
    }

    while(!maxh.empty()){
        res *= maxh.top();
        maxh.pop();
    }
    return res;
}

int main(){
    int arr[] = {198, 76, 544, 123, 154, 675}; 
    int k = 2; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Minimum product is "
         << minProduct(arr, n, k);
    cout<<endl;
    return 0;
}