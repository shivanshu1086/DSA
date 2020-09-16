#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<pair<int,int> > findSubArrays(int *a, int n){
    vector<pair<int,int> > vec;
    map<int,vector<int>> map;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if (sum == 0) 
            vec.push_back(make_pair(0, i));
        
        if(map.find(sum)!=map.end()){
            vector<int> vc = map[sum];
            for (auto it = vc.begin(); it != vc.end(); it++) 
                vec.push_back(make_pair(*it + 1, i));
        }
        map[sum].push_back(i);
    }
    return vec;
}

void print(vector<pair<int,int> > out){
    for (auto it = out.begin(); it != out.end(); it++) 
        cout << "Subarray found from Index " << 
            it->first << " to " << it->second << endl;
}

int main() {
    int arr[] = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<pair<int, int> > out = findSubArrays(arr, n);
    // if we didn’t find any subarray with 0 sum,
    // then subarray doesn’t exists 
    if (out.size()==0)
        cout << "No subarray exists";
    else{
        print(out);
    }
    cout<<endl;
	return 0;
}