#include <iostream>
#include <queue>

using namespace std;

void KMaxCombinations(int A[], int B[], int N, 
                                        int K) 
{ 
    // max heap. 
    priority_queue<int> pq; 
  
    // insert all the possible combinations  
    // in max heap. 
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            pq.push(A[i] + B[j]); 
  
    // pop first N elements from max heap 
    // and display them. 
    int count = 0; 
    while (count < K) { 
        cout << pq.top() << endl; 
        pq.pop(); 
        count++; 
    } 
}

int main(){

    int A[] = { 4, 2, 5, 1 }; 
    int B[] = { 8, 0, 5, 3 }; 
    int N = sizeof(A)/sizeof(A[0]); 
    int K = 3; 
    KMaxCombinations(A, B, N, K); 
    cout<<endl;
    return 0;
}