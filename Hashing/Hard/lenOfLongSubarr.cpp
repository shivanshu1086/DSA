#include <iostream>
#include <unordered_map>
using namespace std;

int lenOfLongSubarr(int *a, int n){
    unordered_map<int,int> map;

    for(int i=0;i<n;i++){
        a[i]= (a[i]==0)?-1:1;
    }

    int max_length = 0;
    int ending_index=-1;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];

        if(sum==1){
            max_length=i+1;
            ending_index=i;
        }

        else if(map.find(sum)==map.end()){
            map[sum]=i;
        }

        if(map.find(sum-1)!=map.end()){
            if(max_length<i-map[sum-1]){
                max_length = i-map[sum-1];
                ending_index=i;
            }
        }
    }
    cout<<ending_index-max_length+1<<" "<<ending_index<<endl;
    return max_length;
}

int main() {
    int arr[] = {0, 1, 1, 0, 0, 1}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Length = "
         << lenOfLongSubarr(arr, n);
    cout<<endl;
	return 0;
}