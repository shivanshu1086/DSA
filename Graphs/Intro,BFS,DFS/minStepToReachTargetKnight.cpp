#include <iostream>
#include <queue>

using namespace std;

class cell{
public:
    int x,y;
    int dis;
    cell(){}

    cell(int x, int y, int dis){
        this->x = x;
        this->y = y;
        this->dis = dis;
    }
};

bool isInsideRenge(int x, int y, int N){
    if(x >= 1 && x <= N && y >= 1 && y <= N)return true;
    return false;
}

int minStepToReachTarget(int *knightPos, int *targetPos, int N){
    // x and y direction, where a knight can move 
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 }; 
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 }; 

    queue<cell> q;
    q.push(cell(knightPos[0],knightPos[1],0));

    cell temp;
    int x,y;
    bool visit[N + 1][N + 1];

    for (int i = 1; i <= N; i++) 
        for (int j = 1; j <= N; j++) 
            visit[i][j] = false;
        

    visit[knightPos[0]][knightPos[1]] = true;

    while(!q.empty()){
        temp = q.front(); 
        q.pop();

        if (temp.x == targetPos[0] && temp.y == targetPos[1]) 
            return temp.dis;

        for(int i=0;i<8;i++){
            x = temp.x + dx[i]; 
            y = temp.y + dy[i];

            if(isInsideRenge(x,y,N) && !visit[x][y]){
                visit[x][y] = true; 
                q.push(cell(x, y, temp.dis + 1));
            }
        }
    }
    return INT_MAX;
}

int main(){
    int N = 6; 
    int knightPos[] = { 1, 1 }; 
    int targetPos[] = { 6, 6 };

    cout << minStepToReachTarget(knightPos, targetPos, N);
    cout<<endl;
    return 0;
}