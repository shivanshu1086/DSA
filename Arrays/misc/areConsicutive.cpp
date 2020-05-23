#include <iostream>
#include <map>
#include <cmath>

using namespace std;
int getMin(int arr[], int n);
int getMax(int arr[], int n) ;

bool areConsicutive(int *a, int n){

    if(n<1) return false;
    int min=getMin(a,n);
    int max=getMax(a,n);

    if(max-min+1==n){
        bool *visited=new bool[n];
        int i;
        for(i=0;i<n;i++){
            //if that element came again
            if(visited[a[i]-min]!=false){
                return false;
            }
            visited[a[i]-min]=true;
        }
        return true;
    }
    return false;
}

int getMin(int arr[], int n) 
{ 
  int min = arr[0]; 
  for (int i = 1; i < n; i++) 
   if (arr[i] < min) 
     min = arr[i]; 
  return min; 
} 
  
int getMax(int arr[], int n) 
{ 
  int max = arr[0]; 
  for (int i = 1; i < n; i++) 
   if (arr[i] > max) 
     max = arr[i]; 
  return max; 
}


//efficient method
bool areConsicutive2(int *a, int n){

    if(n<1) return false;
    int min=getMin(a,n);
    int max=getMax(a,n);

    if(max-min+1==n){
        int i;
        for(i=0;i<n;i++){
            int j;
            if(a[i]<0){
                j=-a[i]-min;
            }
            else{
                j=a[i]-min;
            }

            //repetition check
            if(a[j]>0){
                a[j]=-a[j];
            }
            else{
                return false;
            }
        }
        return true;
    }
    return false;
}
int main()
{
    int a[] = {5, 4, 2, 3, 1, 6};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<boolalpha<<areConsicutive2(a,n);
	cout<<endl;
    return 0;
}
