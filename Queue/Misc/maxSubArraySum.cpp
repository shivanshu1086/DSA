#include <iostream>
#include <queue>

using namespace std;

int maxSubArraySum(int a[], int n, int k){
    int sum=0;

    deque<int> s(k),d(k);

    int i=0;
    for(i=0;i<k;i++){
        while(!s.empty() && a[s.back()]>=a[i]){
            s.pop_back();
        }
        while(!d.empty() && a[d.back()]<=a[i]){
            d.pop_back();
        }

        s.push_back(i);
        d.push_back(i);
    }

    for(;i<n;i++){
        sum+=a[s.front()]+a[d.front()];

        while(!s.empty() && s.front()<=i-k){
            s.pop_front();
        }
        while(!d.empty() && d.front()<=i-k){
            d.pop_front();
        }

        while(!s.empty() && a[s.back()]>=a[i]){
            s.pop_back();
        }
        while(!d.empty() && a[d.back()]<=a[i]){
            d.pop_back();
        }

        s.push_back(i);
        d.push_back(i);
    }

    sum+=a[s.front()]+a[d.front()];
    return sum;
}

int main(){
    int a[]={2, 5, -1, 7, -3, -1, -2};
    int n=sizeof(a)/sizeof(a[0]);
    int k=3;
    cout<<maxSubArraySum(a,n,k);
    cout<<endl;
	return 0;
}