#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

void divisibilityCheck(int arr[], int n) 
{
    unordered_set<int> s; 
    int max_ele = INT_MIN; 
    for (int i = 0; i < n; i++) { 
        s.insert(arr[i]);
        max_ele = max(max_ele, arr[i]); 
    }

    unordered_set<int> res;
    for (int i = 0; i < n; i++) { 
  
        // Check for non-zero values only 
        if (arr[i] != 0) { 
  
            // Checking the factors of current element 
            for (int j = arr[i] * 2; j <= max_ele; j += arr[i]) { 
  
                // If current factor is already part 
                // of the array then store it 
                if (s.find(j) != s.end()) 
                    res.insert(j); 
            } 
        }
    }
    unordered_map<int, int> mp; 
    for (int i = 0; i < n; i++) 
        mp[arr[i]]++;

    unordered_map<int, int>::iterator it; 
    vector<int> ans; 
    for (it = mp.begin(); it != mp.end(); it++){
  
        // If frequency is at least 2 
        if (it->second >= 2) { 
            if (res.find(it->first) == res.end()) { 
  
                // If frequency is greater than 1 and 
                // the number is not divisible by 
                // any other number 
                int val = it->second;
                // Then we push the element number of 
                // times it is present in the vector 
                while (val--) 
                    ans.push_back(it->first); 
            } 
        } 
  
        // If frequency is greater than 1 and the number 
        // is divisible by any other number 
        if (res.find(it->first) != res.end()) { 
            int val = it->second; 
  
            // Then we push the element number of 
            // times it is present in the vector 
            while (val--) 
                ans.push_back(it->first); 
        } 
    } 

    for (auto x : ans) 
        cout << x << " ";
    

}

int main() {
    int arr[] = { 2, 3, 8, 6, 9, 10 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    divisibilityCheck(arr, n);
    cout<<endl;
	return 0;
}