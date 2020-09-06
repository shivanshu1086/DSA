#include <iostream>
#include <queue>

using namespace std;

void generate_smallest_derangement(int N){
    int S[N + 1];
    priority_queue<int, vector<int>, greater<int> > PQ;

    for(int i=1;i<=N;i++){
        S[i]= i;
        PQ.push(i);
    }

    int D[N+1];
    for(int i=1;i<=N;i++){
        int d = PQ.top();
        PQ.pop();

        if(d!=S[i] || i==N){
            D[i]=d;
        }
        else{
            D[i] = PQ.top();
            PQ.pop();
            PQ.push(d);
        }
    }

    if (D[N] == S[N]) 
       swap(D[N-1], D[N]);

    for (int i = 1; i <= N; i++)  
        printf("%d ", D[i]);
}


int main(){
    generate_smallest_derangement(10);
    cout<<endl;
    return 0;
}