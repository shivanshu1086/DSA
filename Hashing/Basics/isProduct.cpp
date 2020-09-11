#include <iostream>
#include <unordered_set>
using namespace std;

bool isProduct(int *a, int n, int x){
    if (n < 2) 
        return false;

    unordered_set<int> s;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            if(x==0){
                return true;
            }
            else{
                continue;
            }
        }

        if(x%a[i] == 0){
            if (s.find(x/a[i]) != s.end()) 
               return true;
            
            s.insert(a[i]);
        }
    }
    return false;
}

int main(){
    int arr[] = {10, 20, 9, 40}; 
    int x = 400; 
  
    int n = sizeof(arr)/sizeof(arr[0]); 
    isProduct(arr, n, x)? cout << "Yes\n"
                       : cout << "No"; 
  
    x = 190; 
    isProduct(arr, n, x)? cout << "Yes\n"
                        : cout << "No";

    cout<<endl;
    return 0;
}