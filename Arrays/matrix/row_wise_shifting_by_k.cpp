#include <iostream>
#include <unordered_map>
#include <map>

#define N 100
using namespace std;

void rotate(int a[], int start, int end){
    while(start<end){
        swap(a[start++],a[end--]);
    }
}

void row_wise_shifting_by_k(int a[][N], int r, int c, int k){
    int i=0;
    while(i<r){
        rotate(a[i],0,k-1);
        rotate(a[i],k,c-1);
        rotate(a[i],0,c-1);
        i++;
    }

    //print the shifted array
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}//actual shifting

//only print from shifted position
void print_shifted(int a[][N], int r, int c, int k){
    int i=0;
    while(i<r){
        for(int j=k;j<c;j++){
            cout<<a[i][j]<<" ";
        }
        for(int j=0;j<k;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
        i++;
    }
}

int main()
{
    int a[][N] = {{ 1, 2, 3, 20}, 
                     {5, 6, 20, 25}, 
                     {1, 3, 5, 6}, 
                     {6, 7, 8, 15}};

    // row_wise_shifting_by_k(a,4,4,2);
    print_shifted(a,4,4,2);
	cout<<endl;
    return 0;
}
