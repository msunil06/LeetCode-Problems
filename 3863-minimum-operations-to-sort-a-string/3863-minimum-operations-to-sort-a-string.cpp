class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if(is_sorted(s.begin(),s.end())){
            return 0;
        }
        if(n<=2){
            return -1;
        }
        char maxEl = *max_element(s.begin(),s.end());
        char minEl = *min_element(s.begin(),s.end());
        if(s[0] == minEl || s[n-1]==maxEl){
            return 1;
        }
        char mid_mx = *max_element(s.begin()+1,s.end()-1);
        char mid_mn = *min_element(s.begin()+1,s.end()-1);
        if(s[0]>mid_mx && s[n-1]<mid_mn){
            return 3;
        }

        return 2;
    }
};