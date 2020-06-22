#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool adjSign(string s, int i){
    if(i==0){
        return true;
    }
    if(s[i-1]=='-'){
        return false;
    }
    return true;
}

void eval(string s, vector<int> &v, bool add){
    stack<bool> stk;
    stk.push(true);

    int i=0;
    while(s[i]!='\0'){
        if(s[i]=='+' ||s[i]=='-'){
            i++;
            continue;
        }

        if(s[i]=='('){
            if(adjSign(s,i)){
                stk.push(stk.top());
            }
            else{
                stk.push(!stk.top());
            }
        }

        else if(s[i]==')'){
            stk.pop();
        }

        else{
            if(stk.top()){
                v[s[i]-'a']+=(adjSign(s,i)? add ? 1 : -1 :
                                            add ? -1 : 1);
            }
            else{
                v[s[i]-'a'] += (adjSign(s,i) ? add ? -1 : 1 :
                                                add ? 1 : -1);
            }
        }
        i++;
    }
}

bool bothAreSame(string s1, string s2){
    vector<int> v(26,0);

    eval(s1,v,true);

    eval(s2,v,false);

    for(int i=0;i<26;i++){
        if(v[i]!=0) return false;
    }
    return true;
}


int main() {
	string s1="-(a+b+c)";
    string s2="-a-b-c";
    if(bothAreSame(s1,s2)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    cout<<endl;
	return 0;
}