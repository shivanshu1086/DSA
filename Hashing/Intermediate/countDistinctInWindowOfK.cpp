#include <iostream>
#include <map>
using namespace std;

void countDistinct(int arr[], int k, int n) 
{
    map<int,int> mp;
    int dist_count = 0;
    for(int i=0;i<k;i++){
        if (mp[arr[i]] == 0) { 
            dist_count++; 
        } 
        mp[arr[i]]++;
    }

    cout << dist_count << endl;

    for(int i=k;i<n;i++){
        if(mp[arr[i-k]]==1){
            dist_count--;
        }

        mp[arr[i-k]] -=1;

        if(mp[arr[i]]==0){
            dist_count++;
        }

        mp[arr[i]]+=1;

        cout<<dist_count<<endl;
    }
}

int main() {
    int arr[] = { 1, 2, 1, 3, 4, 2, 3 }; 
    int size = sizeof(arr) / sizeof(arr[0]); 
    int k = 4; 
    countDistinct(arr, k, size);
    cout<<endl;
	return 0;
}