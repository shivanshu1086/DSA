#include <iostream>
#include <unordered_set>
using namespace std;

bool subArrayExists(int arr[], int n) 
{
    unordered_set<int> set;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        if(set.find(sum)!=set.end()){
            return true;
        }
        set.insert(sum);
    }
    return false;
}

int main() {
    int arr[] =  {4, 2, -3, 1, 6}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    if (subArrayExists(arr, n)) 
        cout << "Found a subarray with 0 sum"; 
    else
        cout << "No Such Sub Array Exists!";
    cout<<endl;
	return 0;
}