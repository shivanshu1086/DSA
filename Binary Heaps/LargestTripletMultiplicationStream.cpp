#include <iostream>
#include<queue>
using namespace std;

void LargestTripletMultiplication(int arr[], int n) 
{
    priority_queue<int> q;

    for (int i = 0; i < n; i++) { 
        q.push(arr[i]);

        if(q.size()<3){
            cout<<"-1"<<endl;
        }
        else{
            int x = q.top(); 
            q.pop(); 
            int y = q.top(); 
            q.pop(); 
            int z = q.top(); 
            q.pop();

            int ans = x * y * z; 
            cout << ans << endl; 
            q.push(x); 
            q.push(y); 
            q.push(z); 
        }
    }
     return; 
}


int main(){
    int arr[] = { 1, 2, 3, 4, 5 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    LargestTripletMultiplication(arr, n);
    cout<<endl;
    return 0;
}