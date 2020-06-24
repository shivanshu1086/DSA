#include <iostream>
#include <vector>
#include <climits>
#include <stack>

using namespace std;

int countTheLengthAfterRemove(vector<string> v){
    stack<string> s;
    for(int i=0;i<v.size();i++){
        if(s.empty()){
            s.push(v[i]);
            continue;
        }
        else if(v[i]==s.top()){
            s.pop();
        }
        else{
            s.push(v[i]);
        }
    }
    return s.size();
}

int main() {
    vector<string> v={"ab","aa","aa", "abcd", "ab"};
    cout<<countTheLengthAfterRemove(v);
    cout<<endl;
	return 0;
}