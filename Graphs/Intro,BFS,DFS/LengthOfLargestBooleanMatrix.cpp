#include <iostream>
#include <vector>
#define ROW 4 
#define COL 5
using namespace std;

int isSafe(int M[][COL], int row, 
           int col, 
           bool visited[][COL]) 
{ 
    // row number is in range, 
    // column number is in 
    // range and value is 1 
    // and not yet visited 
    return (row >= 0) 
           && (row < ROW) 
           && (col >= 0) 
           && (col < COL) 
           && (M[row][col] 
               && !visited[row][col]); 
}

void DFS(int M[][COL], int row, int col, 
         bool visited[][COL], int& count) 
{ 
    // These arrays are used 
    // to get row and column 
    // numbers of 8 neighbours 
    // of a given cell 
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 
  
    // Mark this cell as visited 
    visited[row][col] = true; 
  
    // Recur for all connected neighbours 
    for (int k = 0; k < 8; ++k) { 
        if (isSafe(M, row + rowNbr[k], col + colNbr[k], 
                   visited)) { 
            // Increment region length by one 
            count++; 
            DFS(M, row + rowNbr[k], col + colNbr[k], 
                visited, count); 
        } 
    } 
} 

int largestRegion(int M[][COL]) 
{ 
    // Make a bool array to mark visited cells. 
    // Initially all cells are unvisited 
    bool visited[ROW][COL]; 
    memset(visited, 0, sizeof(visited)); 
  
    // Initialize result as 0 and travesle through the 
    // all cells of given matrix 
    int result = INT_MIN; 
    for (int i = 0; i < ROW; ++i) { 
        for (int j = 0; j < COL; ++j) { 
            // If a cell with value 1 is not 
            if (M[i][j] && !visited[i][j]) { 
                // visited yet, then new region found 
                int count = 1; 
                DFS(M, i, j, visited, count); 
  
                // maximum region 
                result = max(result, count); 
            } 
        } 
    } 
    return result; 
}


int main(){
    int M[][COL] = { { 0, 0, 1, 1, 0 }, 
                     { 1, 0, 1, 1, 0 }, 
                     { 0, 1, 0, 0, 0 }, 
                     { 0, 0, 0, 0, 1 } }; 
  
    cout << largestRegion(M);
    cout<<endl;
    return 0;
}