#include <iostream>
#include <vector>
#include <string>
#include <stack>
#define MAX 1000
using namespace std;


vector<int> nextgreaterleft(int *a, int n){
    vector<int> left_index(MAX,0);
    stack<int> s;

    for(int i=n-1;i>=0;i--){
        while(!(s.empty()) && a[i]>a[s.top()-1]){
            int r=s.top()-1;
            s.pop();
            left_index[r]=i+1;
        }
        s.push(i+1);
    }

    return left_index;
}

vector<int> nextgreaterright(int *a, int n){
    vector<int> right_index(MAX,0);
    stack<int> s;

    for(int i=0;i<n;i++){
        while(!(s.empty()) && a[i]>a[s.top()-1]){
            int r=s.top()-1;
            s.pop();
            right_index[r]=i+1;
        }
        s.push(i+1);
    }
    return right_index;
}

int LRProduct(int *a, int n){
    vector<int> left=nextgreaterleft(a,n);

    vector<int> right=nextgreaterright(a,n);

    vector<int> lr;

    for(int i=0;i<n;i++){
        lr.push_back(left[i]*right[i]);
    }

    return *max_element(lr.begin(),lr.end());
}

int main() 
{
    int a[]={5, 4, 3, 4, 5};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<LRProduct(a,n);
    cout<<endl;
	return 0; 
}