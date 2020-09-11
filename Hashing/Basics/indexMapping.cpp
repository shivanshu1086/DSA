#include <iostream>
#define MAX 1000
using namespace std;
bool has[MAX + 1][2];

bool search(int x){
    return (x>0)?has[x][0]:has[abs(x)][1];
}

void insert(int *a, int n){
    for(int i=0;i<n;i++){
        if(a[i]>=0){
            has[a[i]][0]=1;
        }
        else{
            has[abs(a[i])][1]=1;
        }
    }
}


int main(){
    int a[] = { -1, 9, -5, -8, -5, -2 }; 
    int n = sizeof(a)/sizeof(a[0]); 
    insert(a, n); 
    int X = -5; 
    if (search(X) == true) 
       cout << "Present";  
    else
       cout << "Not Present";
    cout<<endl;
    return 0;
}