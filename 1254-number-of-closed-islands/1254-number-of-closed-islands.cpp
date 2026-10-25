class Solution {
public:
    void dfs(vector<vector<int>>& grid, int x, int y, bool& isClosed) {
    int rows = grid.size();
    int cols = grid[0].size();
    if (x < 0 || y < 0 || x >= rows || y >= cols) {
        isClosed = false;
        return;
    }
    if (grid[x][y] == 1 || grid[x][y] == -1) return;
    grid[x][y] = -1;
    dfs(grid, x + 1, y, isClosed);
    dfs(grid, x - 1, y, isClosed);
    dfs(grid, x, y + 1, isClosed);
    dfs(grid, x, y - 1, isClosed);
}

int closedIsland(vector<vector<int>>& grid) {
    int count = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 0) {
                bool isClosed = true;
                dfs(grid, i, j, isClosed);
                if (isClosed) {
                    count++;
                }
            }
        }
    }
    return count;
}
};