class Solution {
public:
    long long MOD = 1e9 + 7;
    vector<vector<long long>>PT;
    int solve(vector<int> &nums){
        int n = nums.size();
        if(n<=2){
            return 1;
        }
        vector<int>left_array,right_array;
        int root = nums[0];
        for(int i = 1;i<n;i++){
            if(nums[i]<root){
                left_array.push_back(nums[i]);
            }else{
                right_array.push_back(nums[i]);
            }
        }
        long long x = solve(left_array)%MOD;
        long long y = solve(right_array)%MOD;
        long long z = PT[n-1][left_array.size()];

      return ((x*y) % MOD *z) % MOD;
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        PT.resize(n+1);
        for(int i = 0;i<=n;i++){
            PT[i]=vector<long long>(i+1,1);
            for(int j = 1;j<i;j++){
                PT[i][j] = (PT[i-1][j] + PT[i-1][j-1])%MOD;
            }
        }
        return (solve(nums)-1)%MOD;
    }
};