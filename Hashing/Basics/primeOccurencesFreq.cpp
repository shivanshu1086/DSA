#include<iostream>
#include <unordered_map>

using namespace std;

bool is_prime(int n){
    if (n <= 1) return false;
    for(int i=2;i<=n/2;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

void primeOccurences(int arr[],int n, int k) 
{
    unordered_map<int, int> map;
    for(int i=0;i<n;i++){
        map[arr[i]]++;
    }

    for(auto i:map){
        if(i.second>=k && is_prime(i.second)){
            cout<<i.first<<" ";
        }
    }
}

int main() {
    int arr[] = {11, 11, 11, 23,  
                 11, 37, 37, 51,  
                 51, 51, 51, 51}; 
    int k = 2; 
  
    primeOccurences(arr,12, k);
    cout<<endl;
	return 0;
}