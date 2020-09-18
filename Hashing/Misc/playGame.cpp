#include <iostream>
#include <unordered_set>
using namespace std;

int playGame(int arr[], int n) 
{
    unordered_set<int> hash;

    for (int i = 0; i < n; i++) 
        hash.insert(arr[i]);

    return (hash.size() % 2 == 0 ? 1 : 2);
}
//no of count of distinct element is even then first player will win else second.

int main() {
    int arr[] = { 1, 1, 2, 2, 2, 2 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << "Player " << playGame(arr, n) << " Wins" << endl;
    cout<<endl;
	return 0;
}