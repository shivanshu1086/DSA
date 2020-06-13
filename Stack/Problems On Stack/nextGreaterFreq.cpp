#include <iostream>
#include <string>
#include <stack>

using namespace std;

void nextGreaterFreq(int *a, int n, int *freq){
    stack<int> s;
    s.push(0);
    int res[n];
    memset(res,0,sizeof(res));

    for(int i=1;i<n;i++){
        if(freq[a[s.top()]]>freq[a[i]]){
            s.push(i);
        }
        else{
            while(freq[a[s.top()]]<freq[a[i]] && !(s.empty())){
                res[s.top()]=a[i];
                s.pop();
            }
            s.push(i);
        }
    }

    while(!(s.empty())){
        res[s.top()]=-1;
        s.pop();
    }

    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
}

int main() 
{
    int a[]={1, 1, 2, 3, 4, 2, 1};
    int n=sizeof(a)/sizeof(a[0]);
    int maxi = *max_element(a,a+n);
    int freq[maxi+1];
    memset(freq,0,sizeof(freq));
    for(int i=0;i<n;i++){
        freq[a[i]]++;
    }
    nextGreaterFreq(a,n,freq);
    cout<<endl;
	return 0; 
}