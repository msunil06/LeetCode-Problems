class Solution {
public:
    int dp[501][501];
    int solve(string &word1, string &word2,int n, int m){
        if(n==0){
            return m;
        }
        if(m==0){
            return n;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(word1[n-1]==word2[m-1]){
            return dp[n][m] = solve(word1,word2,n-1,m-1);
        }else{
            return dp[n][m]=1 + min(solve(word1,word2,n-1,m-1),min(solve(word1,word2,n-1,m),solve(word1,word2,n,m-1)));
        }
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,word1.size(),word2.size());
    }
};