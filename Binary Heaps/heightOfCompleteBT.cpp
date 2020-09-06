#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int height(int N) 
{ 
    return ceil(log2(N + 1)) - 1; 
} 

int main(){
    int N = 6; 
    cout << height(N); 
    cout<<endl;
    return 0;
}