#include <iostream>
#include <stack>


using namespace std;

bool findRedundantBrackets(string &s){
    stack<char> st;

    for(auto &ch:s){
        if(ch==')'){
            char top = st.top();
            st.pop();

            bool flag=true;

            while(top!='('){
                if(top=='+'||top=='-'||top=='*'||top=='/'){
                    flag=false;
                }
                top=st.top();
                st.pop();
            }

            if(flag==true){
                return true;
            }
        }
        else{
            st.push(ch);
        }
    }
    return false;
}

int main(){
    string s = "((a+b))";
    if(findRedundantBrackets(s)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    cout<<endl;
	return 0; 
}