#include <iostream>
#include <queue>
#include <stack>

using namespace std;

string reverse_string(string s){
    string ans="";
    stack<char> st;
    for(int i=0;i<s.length();i++){
        while(s[i]!=' ' and i<s.length()){
            st.push(s[i++]);
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        ans+=' ';
    }
    return ans;
}

int main(){
    string s="Hello World";
    s=reverse_string(s);
    cout<<s;
    cout<<endl;
	return 0; 
}