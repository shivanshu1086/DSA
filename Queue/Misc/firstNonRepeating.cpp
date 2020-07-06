#include <iostream>
#include <queue>


using namespace std;

void firstNonRepeating(string str){
    queue<char>q;
    int charCount[26]={0};

    for(int i=0;str[i];i++){
        q.push(str[i]);
        charCount[str[i]-'a']++;

        while(!q.empty()){
            if(charCount[str[i]-'a']>1){
                q.pop();
            }
            else{
                cout<<q.front()<<" ";
                break;
            }
        }

        if(q.empty()){
            cout<<"-1"<<" ";
        }
    }
}

int main(){
    char str[]="aabc";
    firstNonRepeating(str);
    cout<<endl;
	return 0;
}