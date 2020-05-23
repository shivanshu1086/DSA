#include <iostream>
#include <unordered_map>

#define N 100
using namespace std;

void maxInEachRow(int a[][N], int n){
    int max=0;
    int max_matrix[n];
    int i=0;
    while(i<n){
        for(int j=0;j<n;j++){
            if(a[i][j]>max){
                max=a[i][j];
            }
        }
        max_matrix[i]=max;
        max=0;
        i++;
    }

    //print the elements
    for(int i=0;i<n;i++){
        cout<<max_matrix[i]<<endl;
    }
}

int main()
{
    int a[][N] = { {3, 4, 1, 8}, 
                        {1, 4, 9, 11}, 
                        {76, 34, 21, 1}, 
                        {2, 1, 4, 5} };

    maxInEachRow(a,4);
	cout<<endl;
    return 0;
}
