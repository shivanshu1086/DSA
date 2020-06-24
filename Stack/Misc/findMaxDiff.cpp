#include <iostream>
#include <vector>
#include <climits>
#include <stack>

using namespace std;

void leftSmaller(int *a, int n, int *LS){
    stack<int> s;
    for(int i=0;i<n;i++){
        while(!s.empty() && s.top()>=a[i]){
            s.pop();
        }

        if(!s.empty()){
            LS[i]=s.top();
        }

        else{
            LS[i]=0;
        }
        s.push(a[i]);
    }
}

int findMaxDiff(int *a, int n){
    int LS[n];
    leftSmaller(a,n,LS);

    int RRS[n];

    reverse(a,a+n);
    leftSmaller(a,n,RRS);

    int result=-1;

    for(int i=0;i<n;i++){
        result=max(abs(LS[i]-RRS[n-1-i]),result);
    }
    return result;
}

int main() {
    int arr[] = {2, 4, 8, 7, 7, 9, 3}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Maximum diff :  "
         << findMaxDiff(arr, n) << endl;
    cout<<endl;
	return 0;
}