#include <iostream>
#include <vector>
#include <climits>
#include <stack>

using namespace std;

void printMinNoForPattern(string s){
    int curr_max=0;

    int last_entry=0;

    int j;

    for(int i=0;i<s.length();i++){
        int noOfNextD=0;

        switch(s[i]){
            case 'I':
                j=i+1;
                while(s[j]=='D' && j<s.length()){
                    noOfNextD++;
                    j++;
                }

                if(i==0){
                    curr_max = noOfNextD+2;
                    cout << " " << ++last_entry; 
                    cout << " " << curr_max;
                    last_entry = curr_max;
                }
                else{
                    curr_max = curr_max+noOfNextD+1;

                    last_entry=curr_max;
                    cout<<" "<<last_entry;
                }

                for(int k=0;k<noOfNextD;k++){
                    cout << " " << --last_entry; 
                    i++;
                }
                break;

            case 'D':
                if(i==0){
                    j=i+1;
                    while(s[j]=='D' && j<s.length()){
                        noOfNextD++;
                        j++;
                    }

                    curr_max = noOfNextD+2;
                    cout << " " << curr_max << " " << curr_max - 1;
                    last_entry = curr_max-1;
                }
                else{
                    cout << " " << last_entry - 1; 
                    last_entry--;
                }
                break;
        }
    }
    cout<<endl;
}

int main() {
    printMinNoForPattern("IDID");
    printMinNoForPattern("I");
    printMinNoForPattern("DD");
    printMinNoForPattern("II");
    printMinNoForPattern("DIDI");
    printMinNoForPattern("IIDDD");
    printMinNoForPattern("DDIDDIID");
    cout<<endl;
	return 0;
}