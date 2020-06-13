#include <iostream>
#include <string>
#include <stack>

using namespace std;

void balanced_paranthesis(string exp){
    stack<char> s;
    char x;
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            s.push(exp[i]);
            continue;
        }
        if(s.empty()){
            cout<<"Not Balanced";
            return;
        }
        switch (exp[i]){
            case ')':
                x=s.top(); s.pop();
                if(x!='('){
                    cout<<"Not Balanced";
                    return;
                }
                break;
            
            case '}':
                x=s.top(); s.pop();
                if(x!='{'){
                    cout<<"Not Balanced";
                    return;
                }
                break;
            
            case ']':
                x=s.top(); s.pop();
                if(x!='['){
                    cout<<"Not Balanced";
                    return;
                }
                break;
        }
    }
    if(s.empty()){
        cout<<"Balanced";
        return;
    }
    cout<<"Not Balanced";
}

int main() 
{
    string exp = "{()}[]";
    balanced_paranthesis(exp);
    cout<<endl;
	return 0; 
}