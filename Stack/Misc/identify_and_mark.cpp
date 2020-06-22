#include <iostream>
#include <stack>


using namespace std;

class pairs{
public:
    char c;
    int index;
};

void identify_and_mark(string s){
    stack<int> st;
    int n=s.length();
    pairs p[n];
    for(int i=0;i<n;i++){
        p[i].index=-12;
    }
    for(int i=0;i<n;i++){
        if(s[i]=='(' || st.empty()){
            st.push(i);
        }
        else if(s[i]==' '){
            continue;
        }
        else if(s[i]==')'){
            int top=st.top();
            st.pop();

            while(!st.empty() && s[top]!='('){
                top=st.top();
                if(s[top]=='('){
                    p[top].c='(';
                    p[top].index=0;
                    p[i].c=')';
                    p[i].index=1;
                }
                st.pop();
            }
            if(s[top]=='('){
                p[top].c='(';
                p[top].index=0;
                p[i].c=')';
                p[i].index=1;
            }
        }
        else{
            st.push(i);
            p[i].c=s[i];
        }
    }

    for(int i=0;i<n;i++){
        if(p[i].c=='(' || p[i].c==')'){
            continue;
        }
        else{
            p[i].c=s[i];
        }
    }
    string ans="";
    for(int i=0;i<n;i++){
        if(p[i].c=='('){
            if(p[i].index!=0){
                p[i].index=-1;
                ans+="-1";
            }
            else{
                ans+='0'+p[i].index;
            }
        }
        else if(p[i].c==')'){
            if(p[i].index!=1){
                p[i].index=-1;
                ans+="-1";
            }
            else{
                ans+='0'+p[i].index;
            }
        }
        else{
            ans+=p[i].c;
        }
    }
    cout<<ans;
}


int main(){
    string s= "(a))";
    identify_and_mark(s);
    // cout<<s;
    cout<<endl;
	return 0; 
}