#include <iostream>
#include <unordered_map>

using namespace std;

int getPairsCount(int *a, int n, int sum){
    unordered_map<int,int> mp;
    int total_pairs = 0;
    for(int i=0;i<n;i++){
        if(mp.find(sum-a[i])!=mp.end()){
            if(mp[a[i]]==a[i]){
                total_pairs+=2;
            }
            else{
                total_pairs++;
            }
        }
        else{
            mp[a[i]]++;
        }
    }
    return total_pairs;
}


int main(){
    int arr[] = {1, 1, 1, 1} ; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int sum = 2; 
    cout << "Count of pairs is " 
         << getPairsCount(arr, n, sum);
    cout<<endl;
    return 0;
}