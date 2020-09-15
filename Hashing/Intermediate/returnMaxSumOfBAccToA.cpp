#include <iostream>
#include <unordered_set>
using namespace std;

int returnMaxSum(int A[], int B[], int n) 
{
    unordered_set<int> mp;

    int result = 0;

    int curr_sum = 0, curr_begin = 0;

    for(int i=0;i<n;i++){
        while (mp.find(A[i]) != mp.end()) { 
            mp.erase(A[curr_begin]); 
            curr_sum -= B[curr_begin]; 
            curr_begin++; 
        }

        mp.insert(A[i]); 
        curr_sum += B[i];

        result = max(result, curr_sum);
    }
    return result;
}

int main() {
    int A[] = { 0, 1, 2, 3, 1, 0, 4 }; 
    int B[] = { 9, 8, 1, 2, 3, 4, 5 }; 
    int n = sizeof(A)/sizeof(A[0]); 
    cout << returnMaxSum(A, B, n);
    cout<<endl;
	return 0;
}