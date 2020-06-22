#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool isMatching(char a, char b){
    if ((a == '{' && b == '}') || (a == '[' && b == ']') 
        || (a == '(' && b == ')') || a == 'X') 
        return 1; 
    return 0; 
}

bool isBalanced(string s, stack<char> st, int ind){
    if(ind==s.length()){
        return st.empty();
    }

    char topEle;
    int res;
    if(s[ind] == '{' || s[ind] == '(' || s[ind] == '['){
        st.push(s[ind]);
        return isBalanced(s,st,ind+1);
    }

    else if(s[ind] == '}' || s[ind] == ')' || s[ind] == ']'){
        if(st.empty()){
            return 0;
        }

        topEle = st.top();
        st.pop();

        if(!isMatching(topEle,s[ind])){
            return 0;
        }

        return isBalanced(s,st,ind+1);
    }

    else if(s[ind]=='X'){
        stack<char> tmp=st;

        tmp.push(s[ind]);

        res=isBalanced(s,tmp,ind+1);

        if(res){
            return 1;
        }
        if(st.empty()){
            return 0;
        }

        st.pop();
        return isBalanced(s,st,ind+1);
    }
}

int main() {
	string s = "{(X}[]"; 
    stack<char> ele; 
    if (isBalanced(s, ele, 0))  
        cout << "Balanced";     
    else 
        cout << "Not Balanced";
    cout<<endl;
	return 0;
}