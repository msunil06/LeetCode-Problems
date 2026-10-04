class Solution {
public:
    int dp[101][101];
    bool solve(int idx,int balance,string s){
        if(balance<0){
            return false;
        }
        if(idx == s.length()){
            return balance == 0;
        }
        int current = s[idx];
        bool result;
        if(dp[idx][balance]!=-1){
            return dp[idx][balance];
        }
        if(current == '('){
            result = solve(idx+1,balance+1,s);
        }
        else if(current == ')'){
          result = solve(idx+1,balance-1,s);
        }
        else{
            bool useAsOpen = solve(idx+1,balance+1,s);
            bool useAsClose = solve(idx+1,balance-1,s);
            bool useAsEmpty = solve(idx+1,balance,s);
            result = useAsOpen|| useAsClose || useAsEmpty;
        }
       return dp[idx][balance]=result;
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s);
        
    }
};