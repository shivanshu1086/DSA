#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

int findRepeatingNumber(const int arr[], int n) 
{
    int sq = sqrt(n);
    int range = (n / sq) + 1;
    int count[range];
    memset(count,0,range);

    for (int i = 0; i <= n; i++) 
    { 
        // arr[i] belongs to block number 
        // (arr[i]-1)/sq i is considered 
        // to start from 0 
        count[(arr[i] - 1) / sq]++; 
    }

    int selected_block = range - 1; 
    for (int i = 0; i < range - 1; i++) 
    { 
        if (count[i] > sq) 
        { 
            selected_block = i; 
            break; 
        } 
    }
    unordered_map<int, int> m; 
    for (int i = 0; i <= n; i++) 
    { 
        // checks if the element belongs to the 
        // selected_block 
        if ( ((selected_block * sq) < arr[i]) && 
                (arr[i] <= ((selected_block + 1) * sq))) 
        { 
            m[arr[i]]++; 
  
            // repeating element found 
            if (m[arr[i]] > 1) 
                return arr[i]; 
        } 
    }
    return-1;
}


int main(){
    const int arr[] = { 1, 1, 2, 3, 5, 4 }; 

    int n = 5; 
  
    cout << "One of the numbers repeated in"
         " the array is: "
         << findRepeatingNumber(arr, n) << endl;
    cout<<endl;
    return 0;
}