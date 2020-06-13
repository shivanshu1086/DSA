#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

vector<int> no_NGN(int *a, int n){
    stack<int> s;
    vector<int> nxt;

    nxt.push_back(0);
    s.push(n-1);

    for(int i=n-2;i>=0;i--){
        while(!(s.empty()) && a[i]>=a[s.top()]){
            s.pop();
        }

        if(s.empty()){
            nxt.push_back(0);
        }

        else{
            nxt.push_back(nxt[n-s.top()-1]+1);
        }
        s.push(i);
    }

    reverse(nxt.begin(), nxt.end());
    return nxt;
}

int main() 
{
    int a[]={3, 4, 2, 7, 5, 8, 10, 6};
    int n=sizeof(a)/sizeof(a[0]);
    vector<int> nxt = no_NGN(a,n);
    cout<<nxt[0]<<endl;
    cout<<nxt[5]<<endl;
    cout<<endl;
	return 0; 
}