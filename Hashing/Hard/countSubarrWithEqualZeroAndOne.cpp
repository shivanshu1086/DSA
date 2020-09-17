#include <iostream>
#include <unordered_map>
using namespace std;

int countSubarrWithEqualZeroAndOne(int *a, int n){
    unordered_map<int,int> map;
    int sum=0;
    int count=0;

    for(int i=0;i<n;i++){
        if(a[i]==0){
            a[i]=-1;
        }

        sum+=a[i];

        if(sum==0){
            count++;
        }

        if(map[sum]){
            count+=map[sum];
        }

        if(map[sum]==0){
            map[sum]=1;
        }
        else{
            map[sum]++;
        }
    }
    return count;
}

int main() {
    int arr[] = {1, 0, 0, 1, 0, 1, 1}; 
  
    int n = sizeof(arr)/sizeof(arr[0]); 
    
    cout<<"count="<<countSubarrWithEqualZeroAndOne(arr, n);
    cout<<endl;
	return 0;
}