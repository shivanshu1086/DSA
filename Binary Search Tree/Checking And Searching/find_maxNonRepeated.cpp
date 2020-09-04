#include <iostream>
#include <map>
#include <set>

using namespace std;

void find_max(int *a, int n, int k){
    map<int, int> count;
    for(int i=0;i<k-1;i++){
        count[a[i]]++;
    }

    set<int> mySet;
    for(auto i:count){
        if(i.second==1){
            mySet.insert(i.first);
        }
    }

    for(int i=k-1;i<n;i++){
        count[a[i]]++;
        if(count[a[i]]==1){
            mySet.insert(a[i]);
        }
        else{
            mySet.erase(a[i]);
        }

        if(mySet.size()==0){
            cout<<"Nothing\n";
        }
        else{
            cout<<*(mySet.begin())<<endl;
        }

        int x = a[i - k + 1];
        count[x]--;
        if (count[x] == 1) 
            mySet.insert(x); 
        if (count[x] == 0) 
            mySet.erase(x);
    }
}

int main(){
    int a[] = { 1, 2, 2, 3, 3 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    int k = 3; 
    find_max(a, n, k);
    return 0;
}