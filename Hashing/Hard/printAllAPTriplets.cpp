#include <iostream>
#include <unordered_set>
using namespace std;

void printAllAPTriplets(int *a, int n){
    unordered_set<int> set;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int diff = a[j]-a[i];
            if(set.find(a[i]-diff)!=set.end()){
                cout<<a[i]-diff<<" "<<a[i]<<" "<<a[j]<<endl;
            }
        }
        set.insert(a[i]);
    }
}

int main() {
    int arr[] = { 2, 6, 9, 12, 17,  
                 22, 31, 32, 35, 42 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    printAllAPTriplets(arr, n);
    cout<<endl;
	return 0;
}