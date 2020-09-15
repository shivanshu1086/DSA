#include <iostream>
#include <unordered_map>

using namespace std;

bool findTriplet(int a1[], int a2[],  
                 int a3[], int n1,  
                 int n2, int n3,  
                 int sum) 
{
    unordered_map<int,int> mp;
    for(int i=0;i<n1;i++){
        mp[a1[i]]++;
    }

    for(int i=0;i<n2;i++){
        for(int j=0;j<n3;j++){
            if(mp.find(sum-a2[i]-a3[j])!=mp.end()){
                return true;
            }
        }
    }
    return false;
}

int main() {
    int a1[] = { 1 , 2 , 3 , 4 , 5 }; 
    int a2[] = { 2 , 3 , 6 , 1 , 2 }; 
    int a3[] = { 3 , 2 , 4 , 5 , 6 }; 
    int sum = 9; 
    int n1 = sizeof(a1) / sizeof(a1[0]); 
    int n2 = sizeof(a2) / sizeof(a2[0]); 
    int n3 = sizeof(a3) / sizeof(a3[0]); 
    findTriplet(a1, a2, a3, n1, n2, n3, sum)? 
    cout << "Yes" : cout << "No";
    cout<<endl;
	return 0;
}