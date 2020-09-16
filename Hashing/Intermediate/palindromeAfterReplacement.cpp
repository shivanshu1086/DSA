#include <iostream>
#include <unordered_set>
using namespace std;

void addRemoveUnequal(string &str, int index, int n, 
                              unordered_set<int> &S) 
{
    if (str[index] == str[n-1-index]) 
    { 
        // Remove the current index from set if it 
        // is present 
        auto it = S.find(index); 
        if (it != S.end()) 
            S.erase(it) ; 
    } 
  
    // If not equal after query, insert it into set 
    else
        S.insert(index);
}

void Query(string &str, int Q) 
{
    int n = str.length();

    unordered_set<int> S;

    for (int i=0; i<n/2; i++) 
        if (str[i] != str[n-1-i]) 
            S.insert(i);
    for (int q=1; q<=Q; q++) 
    {
        int i1, i2; 
        char ch; 
        cin >> i1 >> i2 >> ch; 

        str[i1] = str [i2] = ch; 

        if (i1 > n/2) 
            i1 = n- 1 -i1; 
        if (i2 > n/2) 
            i2 = n -1 - i2;

        addRemoveUnequal(str, i1 , n, S ); 
        addRemoveUnequal(str, i2 , n, S );

        S.empty()? cout << "YES\n" : cout << "NO\n";
    }
}

int main() {
    string str = "geeks"; 
    int Q = 2 ; 
    Query(str, Q);
    cout<<endl;
	return 0;
}