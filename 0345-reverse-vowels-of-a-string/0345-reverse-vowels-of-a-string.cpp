class Solution {
public:
    bool isVowels(char ch){
        char vow = tolower(ch);
        return vow == 'a' || vow == 'e' || vow == 'i' || vow == 'o' || vow == 'u';
    }
    string reverseVowels(string s) {
        int n = s.length();
        int right = n-1;
        for(int left = 0;left<n;left++){
            if(isVowels(s[left])){
                while(left < right && !isVowels(s[right])){
                    right--;
                }
                if(left<right){
                    swap(s[left],s[right]);
                    right--;
                }
            }
        }
        return s;
    }
};