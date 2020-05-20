#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <map>
#include <numeric>
using namespace std;

void majority_element(int *a, int n){
    int max_size=n/2;
    map<int,int> m;
    for(int i=0;i<n;i++){
        m[a[i]]++;
    }
    for(auto i:m){
        if(i.second>max_size){
            cout<<i.first;
            return;
        }
    }
    cout<<"No majority element";
}

int find_may_be_max_ele(int *a, int n){
    int max_ele=0,count=1;
    for(int i=1;i<n;i++){
        if(a[i]==a[max_ele]){
            count++;
        }
        else{
            count--;
        }
        if(count==0){
            max_ele=i;
            count=1;
        }
    }
    return a[max_ele];
}

bool checkformajor(int *a, int n, int x){
    int count=0;
    for(int i=0;i<n;i++){
        if(a[i]==x){
            count++;
        }
    }
    if(count>(n/2)){
        return true;
    }
    else{
        return false;
    }
}

void moore_voting_algo(int *a, int n){
    int may_be_max=find_may_be_max_ele(a,n);
    if(checkformajor(a,n,may_be_max)){
        cout<<may_be_max;
    }
    else{
        cout<<"Not possible";
    }
}

int main()
{
    int a[] ={3, 3, 4, 2, 4, 4, 2, 4, 4};
    int n=sizeof(a)/sizeof(a[0]);
    // majority_element(a,n);
    moore_voting_algo(a,n);
	cout<<endl;
    return 0;
}
