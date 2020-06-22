#include <iostream>
#include <stack>

using namespace std;

void length_of_longest_valid_subs(string s){
    stack<int> st;
    int count=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' or st.empty()){
            st.push(i);
        }
        else{
            int top=st.top();
            st.pop();
            if(!st.empty()){
                count=max(count,i-st.top());
            }
        }
    }
    cout<<count;
}

int main(){
    string s="((()()()()(((())";
    length_of_longest_valid_subs(s);
    cout<<endl;
	return 0; 
}