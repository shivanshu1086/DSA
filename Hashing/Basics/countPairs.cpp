#include<iostream>
#include <set>

using namespace std;


int countPairs(int *a, int n){
    int res=0;
    set< int > Hash;
    for(int i=0;i<n;i++){
        Hash.insert(a[i]);
    }

    for(int i=0;i<n;i++){
        for (int j = i + 1; j<n ; j++) 
        { 
            int product = a[i]*a[j]; 
  
            
            if (Hash.find(product) != Hash.end()) 
                res++; 
        }
    }
    return res;
}

int main() {
	int arr[] = {6 ,2 ,4 ,12 ,5 ,3}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << countPairs(arr, n) ;
    cout<<endl;
	return 0;
}