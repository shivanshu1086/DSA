#include <iostream>
#include<vector>
#include <cmath>
#include <climits>
#include <set>
using namespace std;

int search(int *a, int start, int end, int x){
    if(start<=end){
        int mid=start+((end-start)/2);
        if(a[mid]==x){
            return mid;
        }
        if(x>a[mid]){
            return search(a,mid+1,end,x);
        }
        else{
            return search(a,start,mid-1,x);
        }
    }
    return -1;
}
void insert(int *b, int m, int key){
    b[m]=key;
}

void deleteele(int *b, int m, int key){
    int i;
    for(i=0;i<m;i++){
        if(b[i]==key)
        break;
    }
    for(i;i<m-1;i++){
        b[i]=b[i+1];
    }
}

void search_insert_delete(int *a, int n, int x, int *b, int m, int keytobeadded){
    sort(a,a+n);
    cout<<search(a,0,n-1,x);
    cout<<endl;
    insert(b,m,keytobeadded);
    m=m+1;
    for(int i=0;i<m;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    deleteele(b,m,40);
    m=m-1;
    for(int i=0;i<m;i++){
        cout<<b[i]<<" ";
    }
}


int main()
{
    int a[] = {12, 34, 10, 6, 40};
    int b[20] = {12, 16, 20, 40, 50, 70};
    int n=sizeof(a)/sizeof(a[0]);
    search_insert_delete(a,n,40,b,6,26);
	cout<<endl;
    return 0;
}
