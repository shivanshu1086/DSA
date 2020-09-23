#include <iostream>
#include <vector>
using namespace std;

bool dfs(int residue, int curStep, int wt[], int arr[], 
         int N, int steps) 
{
    if (curStep > steps) 
        return true;

    for(int i=0;i<N;i++){
        int lastW = wt[curStep - 1];
        if(arr[i]>residue && arr[i] != lastW){
            wt[curStep] = arr[i];
            if(dfs(arr[i]-residue, curStep+1, wt, arr, N, steps)){
                return true;
            }
        }
    }
    return false;
}

void printWeightsOnScale(int arr[], int N, int steps) 
{
    int wt[steps];

    if (dfs(0, 0, wt, arr, N, steps)) 
    { 
        for (int i = 0; i < steps; i++) 
            cout << wt[i] << " "; 
        cout << endl; 
    } 
    else
        cout << "Not possible\n";
}

int main(){
    int arr[] = {2, 3, 5, 6}; 
    int N = sizeof(arr) / sizeof(int); 
  
    int steps = 10; 
    printWeightsOnScale(arr, N, steps);
    cout<<endl;
	return 0;
}