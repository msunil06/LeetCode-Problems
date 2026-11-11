class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        long long maxa = max(need1, need2);
        long long mini = min(need1, need2);

        long long ans = LLONG_MAX;

     
        ans = min(ans, 1LL * cost1 * need1
                       + 1LL * cost2 * need2);

     
        ans = min(ans, 1LL * costBoth * maxa);

        
        ans = min(ans, mini * costBoth
                       + (need1 - mini) * cost1
                       + (need2 - mini) * cost2);

        ans = min(ans, 1LL * need1 * costBoth
                       + 1LL * max(0, need2 - need1) * cost2);

        ans = min(ans, 1LL * need2 * costBoth
                       + 1LL * max(0, need1 - need2) * cost1);

        return ans;
    }
};