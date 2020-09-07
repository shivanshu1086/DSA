#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
//one by one arrangement
bool compare(pair<char,int> a, pair<char, int> b){
    return a.second>b.second;
}

void countFreq(map<char, int> &mp, string s){
    for(auto i:s){
        mp[i]++;
    }
    int max_freq = INT_MIN;
    for(auto i:mp){
        if(i.second>max_freq){
            max_freq = i.second;
        }
    }
    if(s.length()-max_freq+1<max_freq){
        cout<<"Not Possible";
        return;
    }

    priority_queue<pair<int,char> >pq;
    for(auto i:mp){
        pq.push(make_pair(i.second,i.first));
    }
    string str = "";
    pair<int,char> prev(-1,'#');
    while(!pq.empty()){
        pair<int,char> p = pq.top();
        pq.pop();
        str = str+ p.second;

        if(prev.first>0){
            pq.push(prev);
        }

        p.first--;
        prev=p;
    }
    cout<<str;
}


void rearrangeString(string s){
    map<char,int> mp;
    countFreq(mp,s);
}

int main(){
    string str = "aaaabb" ; 
    rearrangeString(str);
    cout<<endl;
    return 0;
}