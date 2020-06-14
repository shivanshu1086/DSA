#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;


int applyOp(int a, int b, char op){
    switch(op){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        default: return 0;
    }
}

int evaluate_postfix(string s){
    stack<int> values;
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            continue;
        }

        else if(isdigit(s[i])){
            int num=0; 
            while(isdigit(s[i])){  
                num = num * 10 + (int)(s[i] - '0');
                i++;
            }
            i--;
            values.push(num);
        }

        else{
            int val2=values.top();  values.pop();
            int val1=values.top();  values.pop();
            values.push(applyOp(val1,val2,s[i]));
        }

    }

    return values.top();
}


int main() 
{
    cout<<evaluate_postfix("100 200 + 2 / 5 * 7 +");
    cout<<endl;
	return 0; 
}