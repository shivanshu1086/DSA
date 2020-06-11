#include <iostream>
#include <string>
#include <stack>

using namespace std;

void postfixToPrefix(string exp){
    stack<string> s;
    int l = exp.length();
    for(int i=0;i<l;i++){
        if((exp[i]>='a' && exp[i]<='z')||(exp[i]>='A' && exp[i]<='Z')){
            s.push(string(1,exp[i]));
        }
        else{
            string first_operand = s.top(); s.pop();
            string second_operand = s.top(); s.pop();

            string res = exp[i]+second_operand+first_operand;
            s.push(res);
        }
    }
    cout<<s.top();
}

int main() 
{
    string exp="ABC/-AK/L-*";
    postfixToPrefix(exp);
    cout<<endl;
	return 0; 
}