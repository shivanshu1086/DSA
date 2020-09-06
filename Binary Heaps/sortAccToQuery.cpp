#include <iostream>
#include <queue>

using namespace std;

int query(int start, int end, int k, int n, int *a){
    priority_queue<int> maxh;
    for(int i=start-1;i<end;i++){
        maxh.push(a[i]);
        if(maxh.size()>k){
            maxh.pop();
        }
    }
    return maxh.top();
}


int main(){
    int arr[] = { 3, 2, 5, 1, 8, 9 }; 
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << query(2, 5, 2, n,arr)<< endl;
    cout<<endl;
    return 0;
}