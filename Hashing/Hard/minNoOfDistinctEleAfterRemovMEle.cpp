#include <iostream>
#include <map>
#include <vector>
#include <utility>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    return a.second<b.second;
}

int distinctIds(int arr[], int n, int m) 
{
    map<int,int> map;
    vector<pair<int,int> > vec;
    for(int i=0;i<n;i++){
        map[arr[i]]++;
    }

    for(auto i: map){
        vec.push_back(make_pair(i.first,i.second));
    }

    sort(vec.begin(), vec.end(), compare);

    for(auto i=vec.begin();i!=vec.end();i++){
        if(i->second<=m){
            m=m-i->second;
            i->second=-1;
        }
        else if(i->second>m){
            m=0;
            i->second = i->second-m;
        }
        if(i->second<=0){
            i->second=-1;
        }
        if(m<=0){
            break;
        }
    }
    int count=0;
    for(auto i:vec){
        if(i.second!=-1)
        count++;
    }
    return count;
}

int main() {
    int arr[] = { 2, 4, 1, 5, 3, 5, 1, 3}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    int m = 2; 
  
    cout << distinctIds(arr, n, m);
    cout<<endl;
	return 0;
}