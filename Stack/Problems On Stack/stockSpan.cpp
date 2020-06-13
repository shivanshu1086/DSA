#include <iostream>
#include <string>
#include <stack>

using namespace std;

void stockSpan(int *a, int n){
    // int s[n];
    // s[0]=1;
    // for(int i=1;i<n;i++){
    //     s[i]=1;
    //     for(int j=i-1;((j>=0) && (a[i] >= a[j]));j--){
    //         s[i]++;
    //     }
    // }

    // for(int i=0;i<n;i++){
    //     cout<<s[i]<<" ";
    // }
//----------O(N^2) way------------------------------------//

    stack<int> st;
    st.push(0);
    int s[n];
    s[0]=1;

    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()]<=a[i]){
            st.pop();
        }
        s[i]=(st.empty()) ? (i+1):(i-st.top());
        st.push(i);
    }

    for(int i=0;i<n;i++){
        cout<<s[i]<<" ";
    }
//-------------------O(N)------------------------------------//

    // int ans[n];
    // ans[0]=1;
    // for(int i=1;i<n;i++){
    //     int counter=1;
    //     while((i-counter)>=0 && a[i]>a[i-counter]){
    //         counter+=ans[i-counter];
    //     }
    //     ans[i]=counter;
    // }

    // for(int i=0;i<n;i++){
    //     cout<<ans[i]<<" ";
    // }

}

int main() 
{
    int a[]={100,80,60,70,60,75,85};
    int n=sizeof(a)/sizeof(a[0]);
    stockSpan(a,n);
    cout<<endl;
	return 0; 
}