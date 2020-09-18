#include <iostream>
#include <unordered_set>
using namespace std;

int findArea(int a[], int n) 
{
    unordered_set<int> s;
    int first = 0, second = 0;

    for(int i=0;i<n;i++){
        if(s.find(a[i])==s.end()){
            s.insert(a[i]);
            continue;
        }
        if(a[i]>first){
            second=first;
            first=a[i];
        }
        else if(a[i]>second){
            second=a[i];
        }
    }
    return (first * second);
}

int main() {
    int arr[] = { 4, 2, 1, 4, 6, 6, 2, 5 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << findArea(arr, n);
    cout<<endl;
	return 0;
}