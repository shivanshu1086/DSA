#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <string>
#include <numeric>

#define R 4  
#define C 4
using namespace std;

int first(bool a[], int low, int high){
    if(low<=high){
        int mid=low+(high-low)/2;
        if((a[mid]==0||a[mid-1]==0)&& a[mid]==1){
            return mid;
        }
        else if(a[mid]==0){
            return first(a,mid+1,high);
        }
        return first(a,low,mid-1);
    }
    return -1;
}

int rowWithMax1s(bool a[R][C]){
    int i, index;
    int max_row_index=0;
    int j=first(a[0],0,C-1);//first position of 1 in first row
    //if 1 is not present in the row
    if(j==-1){
        j=C-1;
    }
    for(int i=1;i<R;i++){
        while(j>=0 && a[i][j]==1){
            j--;
            max_row_index=i;
        }
    }
    return max_row_index;
}

int main()
{
    bool mat[R][C] = { {0, 0, 0, 1},  
                        {0, 1, 1, 1},  
                        {1, 1, 1, 1},
                        {0, 0, 0, 0}};

    cout << "Index of row with maximum 1s is " << rowWithMax1s(mat);
	cout<<endl;
    return 0;
}
