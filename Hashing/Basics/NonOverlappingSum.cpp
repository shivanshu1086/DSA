#include <iostream>
#include <unordered_map>
using namespace std;

int findSum(int *a, int *b, int n){
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
        mp[b[i]]++;
    }

    int sum = 0; 
    for (auto x: mp)  
        if (x.second == 1) 
            sum += x.first;
    
    return sum;
}

int main(){
    int A[] = { 5, 4, 9, 2, 3 }; 
    int B[] = { 2, 8, 7, 6, 3 }; 
      
    // size of array 
    int n = sizeof(A) / sizeof(A[0]); 
  
    // function call  
    cout << findSum(A, B, n);
    cout<<endl;
    return 0;
}