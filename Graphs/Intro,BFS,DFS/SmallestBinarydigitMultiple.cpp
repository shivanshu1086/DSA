#include <iostream>
#include <queue>
#include <set>

using namespace std;

int mod(string s, int N){
    int r=0;
    for(int i=0;i<s.length();i++){
        r = r*10 + (s[i]-'0');
        r%=N;
    }
    return r;
}

string getMinimumMultipleOfBinaryDigit(int N) 
{
    queue<string> q; 
    set<int> visit;

    string t = "1";

    q.push(t);
    while(!q.empty()){
        t = q.front();
        q.pop();

        int rem = mod(t, N);

        if (rem == 0) 
            return t;
        
        else if(visit.find(rem)==visit.end()){
            visit.insert(rem);
            q.push(t + "0");
            q.push(t + "1");
        }
    }
    return "";
}

int main(){
    int N = 12; 
    cout << getMinimumMultipleOfBinaryDigit(N);
    cout<<endl;
    return 0;
}