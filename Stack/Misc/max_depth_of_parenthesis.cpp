#include <iostream>
#include <stack>

using namespace std;

void max_depth_of_parenthesis(string s){
    int cur_max=0;
    int max=0;
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            cur_max++;

            if(cur_max>max){
                max=cur_max;
            }
        }

        else if(s[i]==')'){
            if(cur_max>0){
                cur_max--;
            }
            else{
                cout<<"-1";
                return;
            }
        }
    }

    if(cur_max!=0){
        cout<<"-1";
        return;
    }
    cout<<max;
}

int main(){
    string s="( a(b) (c) (d(e(f)g)h) I (j(k)l)m)";
    max_depth_of_parenthesis(s);
    cout<<endl;
	return 0; 
}