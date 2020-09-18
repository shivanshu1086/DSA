#include <iostream>
#include <unordered_map>
using namespace std;

int lastSeenElement(int a[], int n) 
{
    unordered_map<int, int> hash; 
    for (int i = 0; i < n; i++) 
        hash[a[i]] = i;
    
    int res_ind = INT_MAX, res;
    for (auto x : hash) 
    { 
       if (x.second < res_ind) 
       { 
            res_ind = x.second; 
            res = x.first; 
       } 
    }
    return res;
}

int main() {
    int a[] = { 2, 1, 2, 2, 4, 1 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    cout << lastSeenElement(a, n);
    cout<<endl;
	return 0;
}