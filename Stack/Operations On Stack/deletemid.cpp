#include <iostream>
#include <stack>

using namespace std;

void deletemid(stack<char> &s, int n, int count=0){
    if (s.empty() || count == n) 
     return;
    
    int x = s.top(); 
    s.pop();
    deletemid(s, n, count+1);

    if(count!=n/2){
        s.push(x);
    }
}

int main(){
    stack<char> st;
    st.push('1'); 
    st.push('2'); 
    st.push('3'); 
    st.push('4'); 
    st.push('5'); 
    st.push('6'); 
    st.push('7');
    deletemid(st,st.size());
    while (!st.empty()) 
    { 
        char p=st.top(); 
        st.pop(); 
        cout << p << " "; 
    }
    cout<<endl;
	return 0; 
}