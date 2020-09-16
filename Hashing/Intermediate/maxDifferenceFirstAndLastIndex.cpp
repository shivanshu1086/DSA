#include <iostream>
#include <unordered_map>
using namespace std;

int maxDifference(int arr[], int n) 
{
    struct index{
        int f;
        int l;
    };

    unordered_map<int, index> um;

    for (int i=0; i<n; i++) 
    {
        if(um.find(arr[i])==um.end()){
            um[arr[i]].f=i;
        }
        um[arr[i]].l=i;
    }

    int diff, max_diff = INT_MIN;
    unordered_map<int, index>::iterator itr;

    for (itr=um.begin(); itr != um.end(); itr++) 
    {
        diff = (itr->second).l - (itr->second).f;

        if (max_diff < diff) 
            max_diff = diff;
    }
    return max_diff;
}

int main() {
    int arr[] = {2, 1, 3, 4, 2, 1, 5, 1, 7}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Maximum Difference = " 
         <<maxDifference(arr, n);
    cout<<endl;
	return 0;
}