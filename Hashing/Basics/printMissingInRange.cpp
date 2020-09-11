#include <iostream>
#include <unordered_set>
using namespace std;

void printMissing(int *a, int n, int low, int high){
    unordered_set<int> set;

    for(int i=0;i<n;i++){
        set.insert(a[i]);
    }

    for(int i=low;i<=high;i++){
        if(set.find(i)==set.end()){
            cout<<i<<" ";
        }
    }
}


int main(){
    int arr[] = { 1, 3, 5, 4 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int low = 1, high = 10; 
    printMissing(arr, n, low, high);
    cout<<endl;
    return 0;
}