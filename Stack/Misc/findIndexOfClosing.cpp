#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void findIndexOfClosing(string s, int pos){
    int i;
    if(s[pos]!='['){ 
        cout << s << ", " << pos << ": -1\n";
        return;
    }
    stack<int> st;
    for(i=pos;i<s.length();i++){
        if(s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i]==']'){
            st.pop();
            if(st.empty()){
                cout << s << ", " <<  pos << ": " << i << "\n";
                return;
            }
        }
    }

    cout<<"-1"<<endl;
}


int main() {
	findIndexOfClosing("[ABC[23]][89]",0);
	findIndexOfClosing("[ABC[23]][89]",4);
	findIndexOfClosing("[ABC[23]][89]",9);
	findIndexOfClosing("[ABC[23]][89]",1);
    cout<<endl;
	return 0;
}