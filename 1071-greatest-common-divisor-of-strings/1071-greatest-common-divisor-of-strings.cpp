class Solution {
public:
    string solve(string &str1, string &str2){
        if(str1 + str2 != str2 + str1){
            return "";
        }
        int gcdLength = gcd(str1.length(),str2.length());
        return str1.substr(0,gcdLength);
    }
    string gcdOfStrings(string str1, string str2) {
        return solve(str1,str2);
    }
};