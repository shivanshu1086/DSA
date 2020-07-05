#include <iostream>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

void slidingMaximum(int a[], int n, int k){
    priority_queue<int> q;
    int i;
    for(i=0;i<k;i++){
        q.push(a[i]);
    }
    int j=0;
    cout<<q.top()<<" ";
    while(i<n && j<=n-(k-1)){
        int temp=a[j++];
        priority_queue<int> tmp;
        while(q.top()!=temp){
            tmp.push(q.top());
            q.pop();
        }
        q.pop();
        while(!tmp.empty()){
            q.push(tmp.top());
            tmp.pop();
        }
        q.push(a[i++]);
        cout<<q.top()<<" ";
    }
}


// void printMax(int a[], int n, int k){
//     deque<int> d(k);
//     int i;
//     for(i=0;i<k;i++){
//         while(!d.empty() && a[i]>=a[d.back()]){
//             d.pop_back();
//         }
//         d.push_back(i);
//     }

//     for(;i<n;i++){
//         cout<<a[d.front()]<<" ";
//         while(!d.empty() && d.front()<=i-k){
//             d.pop_front();
//         }

//         while(!d.empty() && a[i]>=a[d.back()]){
//             d.pop_back();
//         }

//         d.push_back(i);
//     }
//     cout<<a[d.front()];
// }

int main(){
    int a[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n=sizeof(a)/sizeof(a[0]);
    int k=3;
    slidingMaximum(a,n,k);
    // printMax(a,n,k);
    cout<<endl;
	return 0;
}