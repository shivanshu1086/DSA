#include <iostream>

using namespace std;

void groupElements(int arr[], int n) 
{
    bool *visited = new bool[n];
    for (int i=0; i<n; i++) 
        visited[i] = false;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            cout << arr[i] << " ";
            for(int j=i+1;j<n;j++){
                if(arr[i]==arr[j]){
                    cout<<arr[j]<<" ";
                    visited[j] = true;
                }
            }
        }
    }
    delete [] visited;
}

int main(){
    int arr[] = {4, 6, 9, 2, 3, 4, 9, 6, 10, 4}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    groupElements(arr, n);
    cout<<endl;
    return 0;
}