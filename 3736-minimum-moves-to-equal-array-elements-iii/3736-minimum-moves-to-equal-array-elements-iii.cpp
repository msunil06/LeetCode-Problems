class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int moves = 0;
        int maxEl = *max_element(begin(nums),end(nums));
        for(int i = 0;i<n;i++){
            moves += maxEl - nums[i];
        }
        return moves;
    }
};