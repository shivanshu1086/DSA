#include <iostream>
#include <vector>
#include <climits>
#include <stack>

using namespace std;

string decodeTheString(string str){
    stack<int> s_i;
    stack<char> s_c;
    string temp="";
    string result="";
    for(int i=0;i<str.length();i++){
        int count=0;

        if(str[i]>='0' && str[i]<='9'){
            while(str[i]>='0' && str[i]<='9'){
                count = count*10 + str[i]-'0';
                i++;
            }
            i--;
            s_i.push(count);
        }

        else if(str[i]==']'){
            temp="";
            count=0;
            if(!s_i.empty()){
                count=s_i.top();
                s_i.pop();
            }

            while(!s_c.empty() && s_c.top()!='['){
                temp=s_c.top() + temp;
                s_c.pop();
            }

            if(!s_c.empty() && s_c.top()=='['){
                s_c.pop();
            }

            for(int j=0;j<count;j++){
                result=result+temp;
            }

            for(int j=0;j<result.length();j++){
                s_c.push(result[j]);
            }
            result="";
        }
        else if(str[i]=='['){
            if(str[i-1]>='0' && str[i-1]<='9'){
                s_c.push(str[i]);
            }
            else{
                s_c.push(str[i]);
                s_i.push(1);
            }
        }
        else{
            s_c.push(str[i]);
        }
    }

    while(!s_c.empty()){
        result = s_c.top() +result;
        s_c.pop();
    }
    return result;
}

int main() {
    string str = "3[b2[ca]]"; 
    cout << decodeTheString(str) << endl;
    cout<<endl;
	return 0;
}