class Solution {
public:
    int maxNum(int num){
        priority_queue<int>pq;
        int bigNum = 0;
        while(num>0){
            int digit = num%10;
            pq.push(digit);
            num /= 10;
        }
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            bigNum = bigNum*10 + x;
        }
        return bigNum;

    }
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        priority_queue<int>pq;
        for(int i = 0;i<n;i++){
            int diff = maxNum(nums[i])- nums[i];
            pq.push(diff);
            sum += nums[i];
        }
        while(k>0){
            int x = pq.top();
            pq.pop();
            sum+=x;
            k--;
        }

       return sum; 
    }
};