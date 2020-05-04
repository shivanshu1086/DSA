#include <iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

bool comp(int a, int b) 
{ 
  
// swap not needed 
if((a > 0 && b > 0) ||  (a < 0 && b < 0) ||  (a > 0 && b < 0 )) 
   return false; 
  
// swap needed 
if(a < 0 && b > 0)  
   return true; 
  
// swap not needed 
if((a == 0 && b < 0) ||  (a > 0 && b == 0)) 
   return false; 
  
// swap needed 

return ((a == 0 && b > 0) ||  (a < 0 && b == 0)) ;
} 

void rearrange(int arr[], int n) 
{ 
    sort(arr, arr + n, comp); 
} 

int main() 
{
	int a[]={ -12, 11, -13, -5,  
                  6, -7, 5, -3, -6 };
	int n=sizeof(a)/sizeof(int);
	rearrange(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
    return 0;
}
