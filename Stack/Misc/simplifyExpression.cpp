#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

char *simplify(string s){
    stack<int> st;
    st.push(0);

    int len=s.length();
    int i=0,index=0;
    char *res=new char(len);

    while(i<len){
        if(s[i]=='+'){
            if(st.top()==1){
                res[index++]='-';
            }
            else if(st.top()==0){
                res[index++]='+';
            }
        }

        else if(s[i]=='-'){
            if(st.top()==1){
                res[index++]='+';
            }
            else if(st.top()==0){
                res[index++]='-';
            }
        }

        else if(s[i]=='(' && i>0){
            if(s[i-1]=='-'){
                st.push((st.top()==1)?0:1);
            }
            else if(s[i-1]=='+'){
                st.push(st.top());
            }
        }

        else if(s[i]==')'){
            st.pop();
        }

        else{
            res[index++]=s[i];
        }
        i++;
    }

    return res;
}

int main() {
    string s1 = "a-(b+c)";
    string s2 = "a-(b-c-(d+e))-f";
    cout << simplify(s1) << endl;
    cout << simplify(s2) << endl;
    cout<<endl;
	return 0;
}