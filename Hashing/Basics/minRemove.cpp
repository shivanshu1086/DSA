#include <iostream>
#include <unordered_map>
using namespace std;

int minRemove(int *a, int *b, int n, int m){
    unordered_map<int, int> countA, countB; 
  
    // Count elements of a 
    for (int i = 0; i < n; i++) 
        countA[a[i]]++; 
  
    // Count elements of b 
    for (int i = 0; i < m; i++) 
        countB[b[i]]++;

    int res = 0; 
    for (auto x : countA) 
        if (countB.find(x.first) != countB.end()) 
            res += min(x.second, countB[x.first]);
    
    return res;
}

int main(){
    int a[] = { 1, 2, 3, 4 }; 
    int b[] = { 2, 3, 4, 5, 8 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    int m = sizeof(b) / sizeof(b[0]); 
  
    cout << minRemove(a, b, n, m);
    cout<<endl;
    return 0;
}