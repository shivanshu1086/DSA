#include <iostream>
#include <vector>
#include <climits>
#include <stack>

using namespace std;

bool findDuplicateparenthesis(string str){
    stack<char> stack;
    for(char i:str){
        if(i==')'){
            char top = stack.top();
            stack.pop();
            int elementInside = 0;
            while(top!='('){
                elementInside++;
                top=stack.top();
                stack.pop();
            }
            if(elementInside<1){
                return true;
            }
        }
        else{
            stack.push(i);
        }
    }
    return false;
}

int main() {
    string str = "(((a+(b))+(c+d)))";
    if (findDuplicateparenthesis(str)) 
        cout << "Duplicate Found "; 
    else
        cout << "No Duplicates Found ";
    cout<<endl;
	return 0;
}