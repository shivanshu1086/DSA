#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <string>
#include <numeric>

#define MAX 100
using namespace std;

int binaryMedian(int a[][MAX], int r, int c){
    int min=INT_MAX, max=INT_MIN;
    for(int i=0;i<r;i++){
        if(a[i][0]<min){
            min=a[i][0];
        }
        if(a[i][c-1]>max){
            max=a[i][c-1];
        }
    }//min and max

    int desired=(r*c+1)/2;
    while(min<max){
        int mid=min+(max-min)/2;
        int place=0;
        //find the count of ele smaller than mid
        for(int i=0;i<r;i++){
            int ub=upper_bound(a[i],a[i]+c,mid)-a[i];
            place+=ub;
        }
        if(place<desired){
            min=mid+1;
        }
        else{
            max=mid;
        }
    }
    return min;
}

int main()
{
    int r = 3, c = 3; 
    int m[][MAX]= { {1,3,5}, {2,6,9}, {3,6,9} }; 
    cout << "Median is " << binaryMedian(m, r, c) << endl;
	cout<<endl;
    return 0;
}
