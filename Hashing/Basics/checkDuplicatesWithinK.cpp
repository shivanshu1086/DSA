#include <iostream>
#include <unordered_set>
using namespace std;

bool checkDuplicatesWithinK(int a[], int n, int k) 
{
    unordered_set<int> myset;

    for(int i=0;i<n;i++){
        if(myset.find(a[i])!=myset.end()){
            return true;
        }
        myset.insert(a[i]);

        if (i >= k) 
        myset.erase(a[i-k]);
    }
    return false;
}


int main(){
    int arr[] = {10, 5, 3, 4, 6, 8, 6}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    if (checkDuplicatesWithinK(arr, n, 3)) 
        cout << "Yes"; 
    else
        cout << "No";
    cout<<endl;
    return 0;
}