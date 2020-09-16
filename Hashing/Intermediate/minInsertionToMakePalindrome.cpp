#include <iostream>

using namespace std;

int minInsertion(string str) 
{
    int n = str.length();
    int res = 0;
    int count[26] = { 0 };

    for (int i = 0; i < n; i++) 
        count[str[i] - 'a']++;
    
    for (int i = 0; i < 26; i++) 
        if (count[i] % 2 == 1) 
            res++;

    return (res == 0) ? 0 : res - 1;
}

int main() {
    string str = "geeksforgeeks"; 
    cout << minInsertion(str);
    cout<<endl;
	return 0;
}