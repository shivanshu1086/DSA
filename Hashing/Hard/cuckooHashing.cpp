#include <iostream>
#define MAXN 11 
  
// choices for position 
#define ver 2
using namespace std;

int hashtable[ver][MAXN];
int pos[ver];

void initTable(){
    for(int i=0;i<MAXN;i++){
        for(int j=0;j<ver;j++){
            hashtable[i][j]=INT_MIN;
        }
    }
}

int hasFunction(int function, int key){
    switch (function)
    {
    case 1:
        return key%MAXN;
    case 2:
        return (key/MAXN)%MAXN;
    }
    return -1;
}

void place(int key, int tableID, int cnt, int n){
    if (cnt==n) 
    { 
        printf("%d unpositioned\n", key); 
        printf("Cycle present. REHASH.\n"); 
        return; 
    }

    for(int i=0;i<ver;i++){
        pos[i] = hasFunction(i+1,key);
        if(hashtable[i][pos[i]]==key){
            return;
        }
    }

    if(hashtable[tableID][pos[tableID]]!=INT_MIN){
        int dis = hashtable[tableID][pos[tableID]];
        hashtable[tableID][pos[tableID]] = key;
        place(dis, (tableID+1)%ver, cnt+1, n);
    }
    else{
        hashtable[tableID][pos[tableID]] = key;
    }
}

void printTable(){
    printf("Final hash tables:\n");

    for (int i=0; i<ver; i++, printf("\n")) 
        for (int j=0; j<MAXN; j++) 
            (hashtable[i][j]==INT_MIN)? printf("- "): 
                     printf("%d ", hashtable[i][j]); 
  
    printf("\n");
}

void cuckoo(int keys[], int n) 
{
    initTable();

    for (int i=0, cnt=0; i<n; i++, cnt=0) 
        place(keys[i], 0, cnt, n);
    
    printTable();
}

int main() {
    int keys_1[] = {20, 50, 53, 75, 100, 67, 105, 
                    3, 36, 39}; 
  
    int n = sizeof(keys_1)/sizeof(int); 
  
    cuckoo(keys_1, n);
    int keys_2[] = {20, 50, 53, 75, 100, 67, 105, 
                    3, 36, 39, 6}; 
  
    int m = sizeof(keys_2)/sizeof(int);
    cuckoo(keys_2, m);
    cout<<endl;
	return 0;
}