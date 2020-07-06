#include <iostream>
#include <queue>

using namespace std;

void printFirstNeg(int a[], int n, int k){
    deque<int> dq;
    int i=0;
    for(i=0;i<k;i++){
        if(a[i]<0){
            dq.push_back(i);
        }
    }

    for(;i<n;i++){
        if(!dq.empty()){
            cout<<a[dq.front()]<<" ";
        }
        else{
            cout<<"0"<<" ";
        }

        while((!dq.empty()) && dq.front()<(i-k+1)){
            dq.pop_front();
        }
        if(a[i]<0)
            dq.push_back(i);
    }

    if(!dq.empty()){
        cout<<a[dq.front()];
    }
    else{
        cout<<"0";
    }
}

int main(){
    int a[]={12, -1, -7, 8, -15, 30, 16, 28};
    int n=sizeof(a)/sizeof(a[0]);
    int k=3;
    printFirstNeg(a,n,k);
    cout<<endl;
	return 0;
}