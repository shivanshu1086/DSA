#include <iostream>
#include <queue>
#include <stack>
#define MAXN 10000
using namespace std;

void makePrev(int *a, int n, int *prevBig){
    stack<pair<int,int> > s;
    for(int i=0;i<n;i++){
        prevBig[i]=-1;
        while(!s.empty() && s.top().first<a[i]){
            s.pop();
        }

        if(!s.empty()){
            prevBig[i] = s.top().second;
        }
        s.push(make_pair(a[i],i));
    }
}

void makeNext(int *a, int n, int *nextBig){
    stack<pair<int, int> > s;
    for (int i = n - 1; i >= 0; i--){
        nextBig[i] = i; 
        while (!s.empty() && s.top().first < a[i]) 
            s.pop(); 
  
        if (!s.empty()) 
            nextBig[i] = s.top().second; 
  
        s.push(pair<int, int>(a[i], i)); 
    }
}

int subArrays(int *a, int n){
    int nextBig[MAXN]; 
    int prevBig[MAXN]; 
    int maxi[MAXN]; 
    int ans = 0;

    makePrev(a, n, prevBig);

    makeNext(a, n, nextBig);
    for (int i = 0; i < n; i++) 
        if (nextBig[i] != i) 
            maxi[nextBig[i] - i] = max(maxi[nextBig[i] - i], 
                                       i - prevBig[i]); 
  
    for (int i = 0; i < n; i++) 
        ans += maxi[i];
    return ans;
}

int main(){
    int a[] = {1, 3, 2, 4};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<subArrays(a,n);
    cout<<endl;
	return 0; 
}