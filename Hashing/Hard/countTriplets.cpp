#include <iostream>
#include <unordered_set>
using namespace std;

int countTriplets(int *a, int n, int key){
    unordered_set<int> set;
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int sum_of_two = a[i]*a[j];
            if(sum_of_two==0){
                continue;
            }
            if(key%sum_of_two==0){
                if(set.find(key/sum_of_two)!=set.end())
                count++;
            }
        }
        set.insert(a[i]);
    }
    return count;
}

int main() {
    int arr[] = { 1, 4, 6, 2, 3, 8}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int m = 24; 
  
    cout << countTriplets(arr, n, m);
    cout<<endl;
	return 0;
}