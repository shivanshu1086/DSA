#include<iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int,string> pois;

string secMostRepeated(vector<string> seq){
    priority_queue<pois, vector<pois>, greater<pois> > maxH;
    unordered_map<string,int> mp;
    for(int i=0;i<seq.size();i++){
        mp[seq[i]]++;
    }

    for(auto i:mp){
        maxH.push(make_pair(i.second,i.first));
        if(maxH.size()>2){
            maxH.pop();
        }
    }
    return maxH.top().second;
}

int main() {
    vector<string> seq = {"geeks", "for", "geeks", "for", 
          "geeks", "aaa"}; 
    cout << secMostRepeated(seq);
    cout<<endl;
	return 0;
}