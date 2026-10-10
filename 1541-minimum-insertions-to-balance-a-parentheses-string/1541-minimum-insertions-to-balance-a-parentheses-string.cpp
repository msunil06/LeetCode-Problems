class Solution {
public:
    int minInsertions(string s) {
        int depth = 0;
        int count = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='('){
                depth++;
            }else{
                if(i+1 < s.size() && s[i+1] == ')'){
                    i++;
                }else{
                    count++;
                }
                if(depth>0){
                    depth--;
                }else{
                    count++;
                }
            }
        }
        count += 2*depth;
        return count;
    }
};