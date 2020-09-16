#include <iostream>
#include <unordered_map>
using namespace std;

void subArraySum(int *a, int n, int key){
    unordered_map<int,int> map;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum==key){
            cout << "Sum found between indexes "
                 << 0 << " to " << i << endl; 
            return;
        }

        if(map.find(key-sum)!=map.end()){
            cout << "Sum found between indexes "
                 << map[sum - key] + 1 
                 << " to " << i << endl; 
            return;
        }
        map[sum]=i;
    }
}

int main() {
    int arr[] = {1, 4, 20, 3, 10, 5};
    int n = sizeof(arr)/sizeof(arr[0]); 
    int sum = 33; 
  
    subArraySum(arr, n, sum);
    cout<<endl;
	return 0;
}