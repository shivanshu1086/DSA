#include <iostream>
#include <unordered_set>

using namespace std;

int findRepeating(int arr[], int n) 
{
    int res = 0; 
    for (int i=0; i<n-1; i++) 
        res = res ^ (i+1) ^ arr[i]; 
    res = res ^ arr[n-1]; 
        
    return res;
}
int findRepeating(int arr[], int n) 
{ 
   unordered_set<int> s; 
   for (int i=0; i<n; i++) 
   { 
      if (s.find(arr[i]) != s.end()) 
         return arr[i]; 
      s.insert(arr[i]); 
   } 
     
   // If input is correct, we should  
   // never reach here 
   return -1; 
} 

int main(){
    int arr[] = { 9, 8, 2, 6, 1, 8, 5, 3, 4, 7 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << findRepeating(arr, n);
    cout<<endl;
    return 0;
}