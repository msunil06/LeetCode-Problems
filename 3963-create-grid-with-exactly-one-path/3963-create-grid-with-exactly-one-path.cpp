class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>g(m,string(n,'#'));
        for(int i = 0;i<n;i++){
            g[0][i] = '.';
        }
        for(int i = 1;i<m;i++){
            g[i][n-1] = '.';
        }
        return g;
    }
};