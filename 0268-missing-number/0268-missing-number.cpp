class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalSum = n*(n+1)/2;
        int currentSum = 0;
        for(int num:nums){
            currentSum += num;
        }
       return totalSum - currentSum; 
    }
};