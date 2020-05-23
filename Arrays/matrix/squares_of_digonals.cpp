#include <iostream>
#include <unordered_map>
#include <map>
// #define N 4 
// #define M 6
#define N 100
using namespace std;

void squares_of_digonals(int a[][N], int r, int c){
    for(int i=0;i<c;i++){
        cout<<(a[i][i]*a[i][i])<<" ";
    }//major digonal
    cout<<endl;
    for(int j=0;j<r;j++){
        cout<<(a[j][c-1-j]*a[j][c-1-j])<<" ";
    }//minor digonal
}

int main()
{
    int a[][N] = { { 2, 5, 7 }, 
                       { 3, 7, 2 },  
                       { 5, 6, 9 } };
    squares_of_digonals(a,3,3);
	cout<<endl;
    return 0;
}
