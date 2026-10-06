class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;
        int need = 0;
        for(auto ch:s){
            if(ch =='('){
                st.push('(');
            }else{
                if(!st.empty()){
                    st.pop();
                }else{
                    need++;
                }
            }
        }
        return st.size() + need;
    }
};