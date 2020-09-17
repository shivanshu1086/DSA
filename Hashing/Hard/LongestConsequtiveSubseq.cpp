#include <iostream>
#include <unordered_set>
using namespace std;

int findLongestConseqSubseq(int a[], int n) 
{
    unordered_set<int> set;
    for(int i=0;i<n;i++){
        set.insert(a[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(set.find(a[i]-1)==set.end()){
            int j=a[i];
            while(set.find(j)!=set.end()){
                j++;
            }
            ans = max(ans, j-a[i]);
        }
    }
    return ans;
}

int main() {
    int arr[] = { 1, 94, 93, 1000, 5, 92, 78 }; 
    int n = sizeof(arr) / sizeof(int); 
    cout << findLongestConseqSubseq(arr, n) << endl;
    cout<<endl;
	return 0;
}