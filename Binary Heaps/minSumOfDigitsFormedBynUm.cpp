#include <iostream>
#include <queue>
using namespace std;

int minSum(int *a, int n){
    priority_queue <int, vector<int>, greater<int> > pq;
    string num1="", num2="";
    for(int i=0; i<n; i++) 
        pq.push(a[i]);

    while(!pq.empty()){
        num1 += (48 + pq.top());
        pq.pop();
        if(!pq.empty()){
            num2+=(48+pq.top());
            pq.pop();
        }
    }

    int n1 = atoi(num1.c_str());
    int n2 = atoi(num2.c_str());
    return n1+n2;
}

int alternateMethod(int *a, int n){
    sort(a,a+n);
    int n1=0,n2=0;
    for(int i=0;i<n;i++){
        if(i%2==0){
            n1=(n1*10)+a[i];
        }
        else{
            n2=(n2*10)+a[i];
        }
    }
    return n1+n2;
}

int main(){
    int arr[] = {5, 3, 0, 7, 4};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    cout<<"The required sum is  "<<minSum(arr, n)<<endl;
    cout<<"The required sum is  "<<alternateMethod(arr, n)<<endl;
    cout<<endl;
    return 0;
}