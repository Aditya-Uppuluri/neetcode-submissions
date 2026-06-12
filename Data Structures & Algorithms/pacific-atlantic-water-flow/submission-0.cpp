class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    void dfs(vector<vector<int>>& heights,
             vector<vector<int>>& vis,
             int r, int c,
             int rows, int cols) {

        vis[r][c] = 1;

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < rows &&
               nc >= 0 && nc < cols &&
               !vis[nr][nc] &&
               heights[nr][nc] >= heights[r][c]) {

                dfs(heights, vis, nr, nc, rows, cols);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> pac(rows, vector<int>(cols, 0));
        vector<vector<int>> atl(rows, vector<int>(cols, 0));

        // Pacific: top row
        for(int i = 0; i < cols; i++) {
            if(!pac[0][i])
                dfs(heights, pac, 0, i, rows, cols);
        }

        // Pacific: left column
        for(int i = 0; i < rows; i++) {
            if(!pac[i][0])
                dfs(heights, pac, i, 0, rows, cols);
        }

        // Atlantic: bottom row
        for(int i = 0; i < cols; i++) {
            if(!atl[rows-1][i])
                dfs(heights, atl, rows-1, i, rows, cols);
        }

        // Atlantic: right column
        for(int i = 0; i < rows; i++) {
            if(!atl[i][cols-1])
                dfs(heights, atl, i, cols-1, rows, cols);
        }

        vector<vector<int>> ans;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};