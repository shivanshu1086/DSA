#include <iostream>
#include <unordered_set>
using namespace std;

bool findTriplets(int *a, int n, int key){
    unordered_set<int> set;
    bool is_found=false;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int sum = a[i]+a[j];
            if(set.find(key-sum)!=set.end()){
                cout<<"["<<a[i]<<","<<a[j]<<","<<key-sum<<"]"<<endl;
                is_found=true;
            }
        }
        set.insert(a[i]);
    }
    return is_found;
}

int main() {
    int nums[] = {-2, 0, 1, 1, 2}; 
    int n = sizeof(nums) / sizeof(nums[0]); 
    int sum = 10; 
    if(!findTriplets(nums, n, sum)) 
        cout << "No triplets can be formed.";
    cout<<endl;
	return 0;
}