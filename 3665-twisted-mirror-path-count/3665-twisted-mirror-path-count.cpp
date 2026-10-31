class Solution {
public:
    int Left = 0;
    int Up = 1;
    int MOD = 1e9 + 7;
    int m;
    int n;
    int solve(vector<vector<int>> &grid, int i , int j,int cameFrom,vector<vector<array<int,2>>> &t){
        if(i>=m || j>=n){
            return 0;
        }
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(t[i][j][cameFrom]!=-1){
            return t[i][j][cameFrom];
        }
        if(grid[i][j]==1){
            if(cameFrom == Left){
               return t[i][j][cameFrom] = solve(grid, i+1,j,Up,t);
            }else{
                return t[i][j][cameFrom] = solve(grid,i,j+1,Left,t);
            }
        }
        int totalPathCount = 0;
        totalPathCount = (totalPathCount + solve(grid,i,j+1,Left,t))%MOD;
        totalPathCount = (totalPathCount + solve(grid,i+1,j,Up,t))%MOD;
        return t[i][j][cameFrom] = totalPathCount;
    }
    int uniquePaths(vector<vector<int>>& grid) {
         m = grid.size();
         n = grid[0].size();
        vector<vector<array<int,2>>>t(m,vector<array<int,2>>(n,{-1,-1}));
        return solve(grid,0,0,Left,t);
    }
};