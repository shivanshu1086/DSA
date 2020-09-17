#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;



int findFrequency(unordered_map< int, vector<int> > &store, int n, int left, int right, int element){
    int a = lower_bound(store[element].begin(),store[element].end(),left)-store[element].begin();
    auto dx=store[element].begin();
    cout<<dx.base();

    int b = upper_bound(store[element].begin(),store[element].end(),right)-store[element].begin();

    return b-a;
}

int main() {
    int arr[] = {2, 8, 6, 9, 8, 6, 8, 2, 11}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    unordered_map< int, vector<int> > store;
    for(int i=0;i<n;i++){
        store[arr[i]].push_back(i+1);
    }

    cout << "Frequency of 2 from 1 to 6 = "
         << findFrequency(store, n, 1, 6, 2) <<endl; 
  
    // Print frequency of 8 from position 4 to 9 
    cout << "Frequency of 8 from 4 to 9 = "
         << findFrequency(store, n, 4, 9, 8);
    cout<<endl;
	return 0;
}