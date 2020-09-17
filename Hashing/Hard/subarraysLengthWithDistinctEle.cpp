#include <iostream>
#include <unordered_set>
using namespace std;

int sumoflength(int *a, int n){
    unordered_set<int> s;

    int j = 0, ans = 0;

    for(int i=0;i<n;i++){
        while(j<n && s.find(a[j])==s.end()){
            s.insert(a[j]);
            j++;
        }

        ans += ((j-i)*(j-i+1))/2;
        s.erase(a[i]);
    }
    return ans;
}

int main() {
    int arr[] = {1, 2, 3, 4}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << sumoflength(arr, n) << endl;
    cout<<endl;
	return 0;
}