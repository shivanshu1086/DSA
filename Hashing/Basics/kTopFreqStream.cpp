#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void kTop(int *a, int n, int k){
    vector<int> top(k + 1); 
  
    // array to keep track of frequency 
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) { 
        // increase the frequency 
        freq[a[i]]++; 
  
        // store that element in top vector 
        top[k] = a[i];

        auto it = find(top.begin(), top.end() - 1, a[i]);

        for(int j=distance(top.begin(), it) - 1;j>=0;--j){
            if (freq[top[j]] < freq[top[j + 1]]) 
                swap(top[j], top[j + 1]);
            else if ((freq[top[j]] == freq[top[j + 1]]) 
                     && (top[j] > top[j + 1])) 
                swap(top[j], top[j + 1]); 
            else break;
        }
        for (int l = 0; l < k && top[l] != 0; ++l) 
            cout << top[l] << ' ';
    }
}

int main(){
    int k = 4; 
    int arr[] = { 5, 2, 1, 3, 2 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    kTop(arr, n, k);
    cout<<endl;
    return 0;
}