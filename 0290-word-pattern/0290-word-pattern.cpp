class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.length();
        stringstream ss(s);
        vector<string>words;
        string word;
        unordered_map<char,string>mp1;
        unordered_map<string,char>mp2;
        while(ss >> word){
            words.push_back(word);
        }
        if(pattern.length()!=words.size()){
            return false;
        }
        for(int i = 0;i<n;i++){
            char ch = pattern[i];
            string st = words[i];
            if(mp1.find(ch)!=mp1.end() && mp1[ch] != st){
                return false;
            }
            else if(mp2.find(st)!=mp2.end() && mp2[st] != ch){
                return false;
            }
            else{
                mp1[ch] = st;
                mp2[st] = ch;
            }
        }
        return true;
    }
};