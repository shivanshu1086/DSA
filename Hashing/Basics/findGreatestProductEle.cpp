#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

int findGreatest(int *a, int n){
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }

    sort(a, a+n);

    for(int i=n-1;i>1;i--){
        for(int j=0;j<i && a[j]<=sqrt(a[i]);j++){
            if(a[i]%a[j]==0){
                int result = a[i]/a[j];
                if (result != a[j] && mp[result] > 0) 
                    return a[i];
                // To handle the case like arr[i] = 4 and 
                // arr[j] = 2 
                else if (result == a[j] && mp[result] > 1) 
                    return a[i]; 
            }
        }
    }
    return -1;
}


int main(){
    int arr[] = {17, 2, 1, 15, 30}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << findGreatest(arr, n);
    cout<<endl;
    return 0;
}