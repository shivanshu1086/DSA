#include <iostream>
#include <queue>
using namespace std;

int kSmallest(int *a, int n, int k){
    priority_queue<int> pq;

    for(int i=0;i<n;i++){
        pq.push(a[i]);
        if(pq.size()>k){
            pq.pop();
        }
    }
    return pq.top();
}

int kLargest(int *a, int n, int k){
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=0;i<n;i++){
        pq.push(a[i]);
        if(pq.size()>k){
            pq.pop();
        }
    }
    return pq.top();
}

int main(){
    int a[] = { 12, 3, 5, 7, 4, 19, 26 };
    int n = sizeof(a)/sizeof(a[0]);
    int k=3;
    cout<<kSmallest(a,n,k);
    cout<<endl<<kLargest(a,n,k);
    cout<<endl;
    return 0;
}