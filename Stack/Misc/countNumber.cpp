#include <iostream>
#include <vector>
#include <climits>
#include <stack>

using namespace std;

int countNumber(int n){
    int result=0;

    for(int i=1;i<=9;i++){
        stack<int> s;
        if(i<=n){
            s.push(i);
            result++;
        }
        while (!s.empty()) 
        { 
            int tp = s.top(); 
            s.pop(); 
            for (int j = tp%10; j <= 9; j++) 
            { 
                int x = tp*10 + j; 
                if (x <= n) 
                { 
                    s.push(x); 
                    result++; 
                } 
            } 
        }
    }
    return result;
}

int main() {
    int n = 15; 
    cout << countNumber(n) << endl;
    cout<<endl;
	return 0;
}