#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool findfour(int arr[], int n, int k) 
{
    unordered_map<int, vector<pair<int, int> > > hash;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int sum = arr[i] + arr[j];
            if (hash.find(k - sum) != hash.end()) {
                auto num = hash.find(k - sum);
                vector<pair<int, int> > v = num->second;

                for(int k=0;k<num->second.size();k++){
                    pair<int, int> it = v[k];
                    if (it.first != i && it.first != j &&  
                        it.second != i && it.second != j) 
                        return true;
                }

            }
            hash[sum].push_back(make_pair(i, j));
        }
    }

    hash.clear(); 
    return false;
}

int main() {
    int k = 7; 
    int arr[] = { 1, 5, 1, 0, 6, 0 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    if (findfour(arr, n, k)) 
        cout 
            << "YES" << endl; 
    else
        cout << "NO" << endl; 
    cout<<endl;
	return 0;
}