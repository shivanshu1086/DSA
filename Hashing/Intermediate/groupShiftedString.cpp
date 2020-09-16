#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int ALPHA = 26;

string getDiffString(string str) 
{
    string shift = ""; 
    for (int i = 1; i < str.length(); i++) 
    { 
        int dif = str[i] - str[i-1]; 
        if (dif < 0) 
            dif += ALPHA; 
  
        // Representing the difference as char 
        shift += (dif + 'a'); 
    }
    return shift;
}

void groupShiftedString(string str[], int n) 
{
    map< string, vector<int> > groupMap;

    for (int i = 0; i < n; i++) 
    { 
        string diffStr = getDiffString(str[i]); 
        groupMap[diffStr].push_back(i); 
    }

    for (auto it=groupMap.begin(); it!=groupMap.end(); 
                                                it++) 
    { 
        vector<int> v = it->second; 
        for (int i = 0; i < v.size(); i++) 
            cout << str[v[i]] << " "; 
        cout << endl; 
    }
}

int main() {
    string str[] = {"acd", "dfg", "wyz", "yab", "mop", 
                    "bdfh", "a", "x", "moqs"
                   }; 
    int n = sizeof(str)/sizeof(str[0]); 
    groupShiftedString(str, n);
    cout<<endl;
	return 0;
}