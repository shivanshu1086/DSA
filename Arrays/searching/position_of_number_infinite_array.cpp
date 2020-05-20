#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <unordered_set>
using namespace std;

int binary_search(int *a, int l, int h, int key){
    if(l<=h){
        int mid=l+(h-l)/2;
        if(a[mid]==key){
            return mid;
        }
        else if(a[mid]<key){
            return binary_search(a,mid+1,h,key);
        }
        else{
            return binary_search(a,l,mid-1,key);
        }
    }
    return -1;
}

void position_of_number_infinite_array(int *a, int n, int key){
    int l=0,h=1;
    int val=a[0];
    while(val<key){
        l=h;
        h=2*h;
        val=a[h];
    }
    cout<<binary_search(a,l,h,key);
}


int main()
{
    int a[] ={3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
    int n=sizeof(a)/sizeof(a[0]);
    position_of_number_infinite_array(a,n,10);
	cout<<endl;
    return 0;
}
