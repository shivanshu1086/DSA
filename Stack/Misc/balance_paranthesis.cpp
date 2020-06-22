#include <iostream>
#include <stack>
#include <cmath>
#include <vector>
#include <list>

using namespace std;

int balance_paranthesis(string s){
    int x=s.length();

    stack<char> st;

    for(int i=0;i<x;i++){
        if(s[i]=='}' && !st.empty()){
            if(st.top()=='{'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        else{
            st.push(s[i]);
        }
    }//removes balance ones

    int m = st.size();

    int n=0;
    while(!st.empty() && st.top()=='{'){
        st.pop();
        n++;
    }

    return (m/2+n%2);
}

int main(){
    string s="}}{{";
    if(s.length()%2!=0){
        cout<<"Can't possible";
        return 0;
    }
    else{
        cout<<balance_paranthesis(s);
    }
    cout<<endl;
	return 0; 
}