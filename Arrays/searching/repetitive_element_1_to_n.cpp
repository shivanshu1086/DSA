#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <unordered_set>
using namespace std;

void repetitive_element_1_to_n(int *a, int n){
    unordered_set<int> s;
    for(int i=0;i<n;i++){
        if(s.find(a[i])!=s.end()){
            cout<<a[i];
            return;
        }
        s.insert(a[i]);
    }
}

void another_method(int *a, int n){
    for(int i=0;i<n;i++){
        int element=a[abs(a[i])];
        if(element<0){
            cout<<abs(a[i]);
            return;
        }
        a[abs(a[i])]=-a[abs(a[i])];
    }
}

int main()
{
    int a[] ={1, 5, 1, 2, 3, 4};
    int n=sizeof(a)/sizeof(a[0]);
    repetitive_element_1_to_n(a,n);
    // another_method(a,n);
	cout<<endl;
    return 0;
}
