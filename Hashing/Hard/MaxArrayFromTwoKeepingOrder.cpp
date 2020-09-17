#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
void maximizeTheFirstArray(int A[], int B[], int n) 
{
    vector<int> temp1(A, A+n); 
    vector<int> temp2(B, B+n); 
    sort(temp1.begin(), temp1.end(), greater<int>()); 
    sort(temp2.begin(), temp2.end(), greater<int>());

    unordered_map<int, int> m;
    int i=0,j=0;
    while(m.size()<n){
        if(temp1[i]>=temp2[j]){
            m[temp1[i]]++;
            i++;
        }
        else{
            m[temp2[j]]++;
            j++;
        }
    }

    vector<int> res; 
    for (int i = 0; i < n; i++) 
        if (m.find(A[i]) != m.end()) 
           res.push_back(A[i]);

    for (int i = 0; i < n; i++) 
        if (m.find(B[i]) != m.end() && 
            m[B[i]] == 1) 
           res.push_back(B[i]);


    for (int i = 0; i < n; i++) 
        cout << res[i] << " ";
}

int main() {
    int A[] = { 9, 7, 2, 3, 6 }; 
    int B[] = { 7, 4, 8, 0, 1 }; 
    int n = sizeof(A) / sizeof(A[0]); 
    maximizeTheFirstArray(A, B, n);
    cout<<endl;
	return 0;
}