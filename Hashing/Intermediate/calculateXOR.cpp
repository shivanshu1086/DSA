#include <iostream>
#include <unordered_map>
using namespace std;

int calculate(int a[], int n){
    int *maximum = max_element(a, a + n);

    int frequency[*maximum + 1];
    memset(frequency,0,sizeof(frequency));

    for(int i = 0; i < n; i++) 
    {  
        // Counting frequency 
        frequency[a[i]] += 1; 
    }

    int answer = 0;
    for(int i = 0; i < (*maximum)+1; i++) 
    {  
        // Calculating answer 
        answer = answer + frequency[i] * (frequency[i] - 1) ; 
    } 
    return answer/2;
}

int main() {
    int a[] = {1, 2, 1, 2, 4}; 
    int n = sizeof(a) / sizeof(a[0]);  
        
    // Function calling 
    cout << (calculate(a,n));
    cout<<endl;
	return 0;
}