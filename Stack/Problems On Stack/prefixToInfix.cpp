#include <iostream>
#include <string>
#include <stack>

using namespace std;

void prefixToInfix(string exp){
    stack<string> s;
    int l=exp.length();
    for(int i=l-1;i>=0;i--){
        if((exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z')){
            s.push(string(1,exp[i]));
        }
        else{
            string first_operand = s.top();
            s.pop();
            string second_operand = s.top();
            s.pop();
            string res = "(" + first_operand + exp[i] + second_operand + ")";
            s.push(res);
        }
    }
    cout<<s.top();
}

int main() 
{
    string exp="*-a/BC-/AKL";
    prefixToInfix(exp);
    cout<<endl;
	return 0; 
} 
