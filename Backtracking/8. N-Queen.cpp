// ***** Problem 1 :- *****

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

// Example 1:
// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above


// Example 2:
// Input: n = 1
// Output: [["Q"]]
 

// Constraints:
// 1 <= n <= 9



// <===================   Placing Queens   ==========================>
class Solution {
public:
    bool isItSafe(vector<string>& grid,int n,int row,int col){
        // Checking for Row
        for(int i=0;i<n;i++)
            if(grid[row][i]=='Q' and i!=col)    return false;
        
        // Checking for Column
        for(int i=0;i<n;i++)
            if(grid[i][col]=='Q' and i!=row)    return false;
        
        // Cheking Right Diagonal Down
        int i=row,j=col;
        while(i<n and j<n and i>=0 and j>=0){
            if(grid[i][j]=='Q' and i!=row and j!=col)   return false;
            i++;
            j++;
        }
        
        // Checking Right Diagonal Up
        i=row,j=col;
        while(i<n and j<n and i>=0 and j>=0){
            if(grid[i][j]=='Q' and i!=row and j!=col)   return false;
            i--;
            j++;
        }
        
        // Checking Left Diagonal Down
        i=row,j=col;
        while(i<n and j<n and i>=0 and j>=0){
            if(grid[i][j]=='Q' and i!=row and j!=col)   return false;
            i++;
            j--;
        }
        
        // Checking Left Diagonal Up
        i=row,j=col;
        while(i<n and j<n and i>=0 and j>=0){
            if(grid[i][j]=='Q' and i!=row and j!=col)   return false;
            i--;
            j--;
        }
        
        return true;
    }
    
    void placeQueens(vector<vector<string>>& ans,vector<string>& grid,int n,int row){
        if(row==n){
            ans.push_back(grid);
            return;
        }
        for(int i=0;i<n;i++){
            grid[row][i] = 'Q';
            if(isItSafe(grid,n,row,i))
                placeQueens(ans,grid,n,row+1);
            grid[row][i] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> grid(n,string(n,'.'));
        placeQueens(ans,grid,n,0);
        return ans;
    }
};



// ***** Problem 2 :- *****

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return the number of distinct solutions to the n-queens puzzle.

// Example 1:
// Input: n = 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown.


// Example 2:
// Input: n = 1
// Output: 1
 

// Constraints:
// 1 <= n <= 9

// <===================== Returing total number of ways to place queens ======================>
class Solution {
public:
    bool isItSafe(vector<vector<bool>>& grid,int n,int row,int col){
        for(int i=0;i<n;i++)
            if(grid[row][i] and i!=col) return false;
        
        for(int i=0;i<n;i++)
            if(grid[i][col] and i!=row) return false;
        
        int i=row,j=col;
        while(i<n and i>=0 and j<n and j>=0){
            if(grid[i][j] and i!=row and j!=col)  return false;
            i++;
            j++;
        }
        
        i=row,j=col;
        while(i<n and i>=0 and j<n and j>=0){
            if(grid[i][j] and i!=row and j!=col) return false;
            i--;
            j--;
        }
        
        i=row,j=col;
        while(i<n and i>=0 and j<n and j>=0){
            if(grid[i][j] and i!=row and j!=col) return false;
            i--;
            j++;
        }
        
        i=row,j=col;
        while(i<n and i>=0 and j<n and j>=0){
            if(grid[i][j] and i!=row and j!=col) return false;
            i++;
            j--;
        }
        
        return true;
    }
    
    int totalQueens=0;
    
    void placeQueens(vector<vector<bool>>& grid,int n,int row){
        if(row==n){
            totalQueens++;
            return;
        }
        for(int i=0;i<n;i++){
            grid[row][i] = true;
            if(isItSafe(grid,n,row,i))
                placeQueens(grid,n,row+1);
            grid[row][i] = false;
        }
    }
    
    int totalNQueens(int n) {
        vector<vector<bool>> grid(n,vector<bool>(n,false));
        placeQueens(grid,n,0);
        return totalQueens;
    }
};
