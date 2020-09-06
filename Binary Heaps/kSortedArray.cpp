#include <iostream>
#include <queue>
using namespace std;

void sortArray(int *a, int n, int k){
    priority_queue<int, vector<int>, greater<int> > minH(a,a+k+1);
    int j=0;

    for(int i=k+1;i<n;i++){
        a[j++] = minH.top();
        minH.pop();
        minH.push(a[i]);
    }

    while(!minH.empty()){
        a[j++] = minH.top();
        minH.pop();
    }
}


void printArray(int arr[], int size) 
{ 
    for (int i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
}

int main(){
    int a[] ={ 2, 6, 3, 12, 56, 8 };
    int n = sizeof(a)/sizeof(a[0]);
    int k=3;
    sortArray(a,n,k);
    printArray(a,n);
    cout<<endl;
    return 0;
}