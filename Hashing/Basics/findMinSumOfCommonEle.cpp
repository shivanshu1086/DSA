#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void find(vector<string> list1, vector<string> list2){
    unordered_map<string, int> map;

    for (int i = 0; i < list1.size(); i++)  
        map[list1[i]] = i;
    
    vector<string> res;

    int minsum = INT_MAX;

    for(int i=0;i<list2.size();i++){
        if(map.count(list2[i])){
            int sum = i+map[list2[i]];
            if(sum<minsum){
                minsum = sum;
                res.clear();
                res.push_back(list2[i]);
            }
            else if(sum==minsum){
                res.push_back(list2[i]);
            }
        }
    }

    for(auto i:res){
        cout<<i<<" ";
    }
}


int main(){
    vector<string> list1; 
    list1.push_back("GeeksforGeeks"); 
    list1.push_back("Udemy"); 
    list1.push_back("Coursera"); 
    list1.push_back("edX"); 
  
    // Creating list2 
    vector<string> list2; 
    list2.push_back("Codecademy"); 
    list2.push_back("Khan Academy"); 
    list2.push_back("GeeksforGeeks"); 
  
    find(list1, list2);
    cout<<endl;
    return 0;
}