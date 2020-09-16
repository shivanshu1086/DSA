#include <iostream>
#include <unordered_map>
using namespace std;

void sortUsingHash(int a[], int n) 
{
    int max = *std::max_element(a, a + n); 
    int min = abs(*std::min_element(a, a + n));

    int hashpos[max + 1];
    memset(hashpos,0,sizeof(hashpos));
    int hashneg[min + 1];
    memset(hashneg,0,sizeof(hashneg));

    for (int i = 0; i < n; i++) { 
        if (a[i] >= 0) 
            hashpos[a[i]] += 1; 
        else
            hashneg[abs(a[i])] += 1; 
    } 

    for (int i = min; i > 0; i--) { 
        if (hashneg[i]) { 
  
            // print the element that number of times  
            // it's present. Print the negative element 
            for (int j = 0; j < hashneg[i]; j++) {                 
                cout << (-1) * i << " "; 
            } 
        } 
    }

    for (int i = 0; i <= max; i++) { 
  
        // if present 
        if (hashpos[i]) { 
  
            // print the element that number of times 
            // it's present 
            for (int j = 0; j < hashpos[i]; j++) { 
                 cout << i << " "; 
            } 
        } 
    }
}

int main() {
    int a[] = { -1, -2, -3, -4, -5, -6, 8, 7, 
                        5, 4, 3, 2, 1, 0 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    sortUsingHash(a, n);
    cout<<endl;
	return 0;
}