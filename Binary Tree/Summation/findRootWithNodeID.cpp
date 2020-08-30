#include <iostream>

using namespace std;

int findRoot(pair<int, int> arr[], int n) 
{
    int root = 0; 
   for (int i=0; i<n; i++) 
     root += (arr[i].first - arr[i].second); 
  
   return root;
}

int main(){
    pair<int, int> arr[] = {{1, 5}, {2, 0}, 
           {3, 0}, {4, 0}, {5, 5}, {6, 5}}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printf("%d\n", findRoot(arr, n));
    cout<<endl;
    return 0;
}