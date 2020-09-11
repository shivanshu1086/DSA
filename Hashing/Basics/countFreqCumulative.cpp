#include<iostream>
#include <unordered_map>
using namespace std;

void countFreq(int a[], int n) 
{
    unordered_map<int, int> hm;
    for (int i=0; i<n; i++) 
        hm[a[i]]++; 
    int cumul = 0;

    for(int i=0;i<n;i++) 
   {
       cumul += hm[a[i]];
       if(hm[a[i]]) 
       { 
           cout << a[i] << "->" << cumul << endl; 
       }
       hm[a[i]]=0;
   }
}


int main() {
    int a[] = {1, 3, 2, 4, 2, 1}; 
    int n = sizeof(a)/sizeof(a[0]); 
    countFreq(a, n);
    cout<<endl;
	return 0;
}