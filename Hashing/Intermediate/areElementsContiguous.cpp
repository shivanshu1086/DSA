#include <iostream>

using namespace std;

bool areElementsContiguous(int arr[], int n) 
{
    int max = *max_element(arr, arr + n); 
    int min = *min_element(arr, arr + n);

    int m = max-min+1;

    if (m > n) 
        return false;
    
    bool visited[m];
    memset(visited,false,sizeof(visited));

    for(int i=0;i<n;i++){
        visited[arr[i]-min] = true;
    }

    for (int i=0; i<m; i++) 
    if (visited[i] == false) 
            return false;
    
    return true;
}

int main() {
    int arr[] = { 5, 2, 3, 6, 
                  4, 4, 6, 6 }; 
  
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    if (areElementsContiguous(arr, n)) 
        cout << "Yes"; 
    else
        cout << "No";
    cout<<endl;
	return 0;
}