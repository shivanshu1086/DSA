#include <iostream>
#include <unordered_set>
using namespace std;

int find(int a[], int b[], int k, int n1, int n2) 
{
    unordered_set<int> set;
    for(int i=0;i<n2;i++){
        set.insert(b[i]);
    }

    int missing=0;
    for(int i=0;i<n1;i++){
        if(set.find(a[i])==set.end()){
            missing++;
        }
        if (missing == k) 
            return a[i];
    }
    return -1;
}


int main(){
    int a[] = { 0, 2, 4, 6, 8, 10, 12, 14, 15 }; 
    int b[] = { 4, 10, 6, 8, 12 }; 
    int n1 = sizeof(a) / sizeof(a[0]); 
    int n2 = sizeof(b) / sizeof(b[0]); 
  
    int k = 3; 
    cout << find(a, b, k, n1, n2);
    cout<<endl;
    return 0;
}