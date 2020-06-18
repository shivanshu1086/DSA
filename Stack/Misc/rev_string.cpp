#include <iostream>
#include <stack>

using namespace std;

void rev_string(string s){
    stack<char> st;
    for(int i=0;s[i]!='\0';i++){
        st.push(s[i]);
    }

    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}//using extra space

//without space

void rev(string s){
    for(int i=0;i<s.length()/2;i++){
        swap(s[i],s[s.length()-i-1]);
    }

    for(int i=0;i<s.length();i++){
        cout<<s[i];
    }
}

int main(){
    string s="ziuQskeeG";
    // rev_string(s);
    rev(s);
    cout<<endl;
	return 0; 
}