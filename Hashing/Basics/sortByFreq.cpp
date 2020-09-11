#include<iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int, int> m2; 
bool sortByVal(const pair<int, int>& a, const pair<int, int>& b) 
{ 
    // If frequency is same then sort by index 
    if (a.second == b.second)  
        return m2[a.first] < m2[b.first]; 
      
    return a.second > b.second; 
}

void sortByFreq(int *a, int n){
    unordered_map<int, int> m; 
    vector<pair<int, int> > v;

    for (int i = 0; i < n; ++i) { 
  
        // Map m is used to keep track of count  
        // of elements in array 
        m[a[i]]++; 
  
        // Update the value of map m2 only once 
        if (m2[a[i]] == 0)  
            m2[a[i]] = i + 1;         
    }
    copy(m.begin(), m.end(), back_inserter(v));
    sort(v.begin(), v.end(), sortByVal);

    for (int i = 0; i < v.size(); ++i)  
        for (int j = 0; j < v[i].second; ++j)  
            cout << v[i].first << " ";
}


int main() {
    int a[] = { 2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8 }; 
    int n = sizeof(a) / sizeof(a[0]); 
  
    sortByFreq(a, n);
    cout<<endl;
	return 0;
}