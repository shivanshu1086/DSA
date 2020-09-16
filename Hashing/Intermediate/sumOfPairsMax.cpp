#include <iostream>
#include <unordered_map>
using namespace std;

int sum(int a[], int n) 
{
    unordered_map<int,int> cnt;
    int ans = 0, pre_sum = 0;

    for(int i=0;i<n;i++){
        ans += (i * a[i]) - pre_sum; 
        pre_sum += a[i];

        if (cnt[a[i] - 1]) 
            ans -= cnt[a[i] - 1];
        
        if (cnt[a[i] + 1]) 
            ans += cnt[a[i] + 1];

        // keeping a counter for every element 
        cnt[a[i]]++;
    }
    return ans;
}

int main() {
    int a[] = { 1, 2, 3, 1, 3 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    cout << sum(a, n);
    cout<<endl;
	return 0;
}