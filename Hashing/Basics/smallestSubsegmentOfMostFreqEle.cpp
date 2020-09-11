#include <iostream>
#include <unordered_map>

using namespace std;

void smallestSubsegment(int *a, int n){
    unordered_map<int, int> left;
    unordered_map<int, int> count;
    unordered_map<int, int> right;

    int mx = 0;
    int res = -1;
    for(int i=0, j=n-1;i<n&&j>=0;i++,j--){
        count[a[i]]++;
        left[a[i]]=i;
        right[a[j]]=j;
    }

    for(auto i:count){
        if(mx<i.second){
            res = i.first;
            mx = i.second;
        }
    }

    int left_index = left[res];
    int right_index = right[res];

    for(int i=right_index;i<=left_index;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    int A[] = {1, 2, 2, 3, 1}; 
    int n = sizeof(A) / sizeof(A[0]); 
    smallestSubsegment(A, n);
    cout<<endl;
    return 0;
}