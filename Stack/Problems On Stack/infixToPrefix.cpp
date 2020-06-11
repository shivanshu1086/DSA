#include <iostream>
#include <string>
#include <stack>

using namespace std;

int prec(char a){
    if(a=='^'){
        return 3;
    }
    else if(a=='*'||a=='/'){
        return 2;
    }
    else if(a=='+'||a=='-'){
        return 1;
    }
    else{
        return -1;
    }
}


string infixToPostfix(string exp){
    stack<char> s;
    s.push('N');
    int l=exp.length();
    string res="";
    for(int i=0;i<l;i++){
        if((exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z')){
            res+=exp[i];
        }

        else if(exp[i] == '('){
            s.push(exp[i]);
        }

        else if(exp[i] == ')'){
            while(s.top()!='N' && s.top()!='('){
                res+=s.top();
                s.pop();
            }

            if(s.top()=='('){
                s.pop();
            }
        }

        else{
            while(s.top()!='N' && prec(exp[i])<=prec(s.top())){
                res+=s.top();
                s.pop();
            }
            s.push(exp[i]);
        }
    }

    while(s.top()!='N'){
        res+=s.top();
        s.pop();
    }

    return res;
}

void infixToPrefix(string exp){
    reverse(exp.begin(),exp.end());
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='('){
            exp[i]=')';
            i++;
        }
        else if(exp[i]==')'){
            exp[i]='(';
            i++;
        }
    }
    string prefix = infixToPostfix(exp);
    reverse(prefix.begin(),prefix.end());
    cout<<prefix;
}

int main() 
{
    string exp = "(a-b/c)*(a/k-l)";
    infixToPrefix(exp);
    cout<<endl;
	return 0; 
}