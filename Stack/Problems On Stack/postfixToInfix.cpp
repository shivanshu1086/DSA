#include <iostream>
#include <string>
#include <stack>

using namespace std;

void postfixToInfix(string exp){
    stack<string> s;
    for(int i=0;exp[i]!='\0';i++){
        if((exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z')){
            s.push(string(1,exp[i]));
        }
        else{
            string first_operand = s.top(); s.pop();
            string second_operand = s.top(); s.pop();
            string res = "(" + second_operand + exp[i] + first_operand + ")";
            s.push(res);
        }
    }
    cout<<s.top();
}

int main() 
{
    string exp ="ab*c+";
    postfixToInfix(exp);
    cout<<endl;
	return 0; 
}