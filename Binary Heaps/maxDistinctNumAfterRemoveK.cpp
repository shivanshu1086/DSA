#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int maxDistinctNum(int arr[], int n, int k) 
{
    unordered_map<int, int> um; 
  
    // priority_queue 'pq' implemented as 
    // max heap 
    priority_queue<int> pq; 
  
    // storing frequency of each element in 'um' 
    for (int i = 0; i < n; i++) 
        um[arr[i]]++; 

    for (auto it = um.begin(); it != um.end(); it++) 
        pq.push(it->second); 
    
    while (k--) { 
  
        // get the top element of 'pq' 
        int temp = pq.top(); 
  
        // remove top element from 'pq' 
        pq.pop(); 
  
        // decrement the popped element by 1 
        temp--; 
  
        // if true, then push the element in 'pq' 
        if (temp != 0) 
            pq.push(temp); 
    }

    int res = 0; 
    while (pq.empty() == false) 
    { 
        int x = pq.top(); 
        pq.pop(); 
        if (x == 1) 
          res++; 
    }       
  
    return res;
}

int main(){
    int arr[] = { 5, 7, 5, 5, 1, 2, 2 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 3; 
    cout << "Maximum distinct elements = "
         << maxDistinctNum(arr, n, k); 
    cout<<endl;
    return 0;
}