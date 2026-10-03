class Solution {
public:
    int dp[201][201];
    int solve(int i , int j,vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        if(i == m-1 && j==n-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down = INT_MAX; 
        int right = INT_MAX;
        if(i+1<m){
            down = solve(i+1,j,grid);
        }
        if(j+1<n){
            right = solve(i,j+1,grid);
        }
        return dp[i][j]= grid[i][j]+min(down,right);
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,grid);
        
    }
};