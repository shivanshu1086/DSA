#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

bool compare(pair<char,int> a, pair<char,int> b){
    return a.second>b.second;
}

int minStringValue(string s, int k){
    map<char,int>mp;
    for(int i=0;i<s.length();i++){
        mp[s[i]]++;
    }

    vector<pair<char,int> > v;
    for(auto i:mp){
        v.push_back(make_pair(i.first,i.second));
    }

    int i=0;
    while(k--){
        if(i<v.size() && v[i].second>0){
            sort(v.begin(),v.end(),compare);
            v[i].second--;
        }
        else{
            i++;
        }
    }

    int ans = 0;
    for(auto i:v){
        ans += (pow(i.second,2));
    }
    return ans;
}

int main(){
    string str = "abccc";
    int k = 1; 
    cout << minStringValue(str, k) << endl; 
  
    str = "aaab";
    k = 2; 
    cout << minStringValue(str, k);
    cout<<endl;
	return 0;
}