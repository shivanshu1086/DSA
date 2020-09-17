#include <iostream>
#include <unordered_set>
using namespace std;

int sumOfDiv(int key){
    int sum=1;
    for(int i=2;i<=sqrt(key);i++){
        if(key%i==0){
            sum += i;

            if (key / i != i) 
                sum += key / i;
        }
    }
    return sum;
}
bool isAmicable(int a, int b) 
{ 
    return (sumOfDiv(a) == b &&  
            sumOfDiv(b) == a); 
}

int countPairs(int arr[], int n) 
{
    unordered_set<int> s; 
    int count = 0; 
    for (int i = 0; i < n; i++) 
        s.insert(arr[i]);

    for (int i = 0; i < n; i++)  
    { 
        if (s.find(sumOfDiv(arr[i])) != s.end())  
        { 
            // It's sum of proper divisors 
            int sum = sumOfDiv(arr[i]); 
            if (isAmicable(arr[i], sum)) 
                count++; 
        } 
    }
    return count/2;
}

int main() {
    int arr1[] = { 220, 284, 1184,  
                   1210, 2, 5 }; 
    int n1 = sizeof(arr1) / sizeof(arr1[0]); 
    cout << countPairs(arr1, n1)  
         << endl; 
      
    int arr2[] = { 2620, 2924, 5020,  
                   5564, 6232, 6368 }; 
    int n2 = sizeof(arr2) / sizeof(arr2[0]); 
    cout << countPairs(arr2, n2)  
         << endl;
    cout<<endl;
	return 0;
}