#include <iostream>
#include <unordered_map>
using namespace std;

void findSubArray(int *a, int n){
    unordered_map<int, int> hM;

    int sum=0;
    int max_len=0;
    int ending_index=-1;

    for(int i=0;i<n;i++){
        a[i] = (a[i]==0)?-1:1;
    }

    for(int i=0;i<n;i++){
        sum+=a[i];

        if(sum==0){
            max_len=i+1;
            ending_index=i;
        }

        if(hM.find(sum+n)!=hM.end()){
            if(max_len<i-hM[sum+n]){
                max_len = i-hM[sum+n];
                ending_index =i;
            }
        }
        else{
            hM[sum+n] = i;
        }
    }

    for(int i=0;i<n;i++){
        a[i] = (a[i]==-1)?0:1;
    }

    cout<<ending_index-max_len+1<<" to "<<ending_index;
}

int main() {
    int arr[] = { 1, 0, 0, 1, 0, 1, 1 }; 
    int size = sizeof(arr) / sizeof(arr[0]); 
  
    findSubArray(arr, size);
    cout<<endl;
	return 0;
}