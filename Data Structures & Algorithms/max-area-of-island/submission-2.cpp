class Solution {
public:
    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,1,0,-1};

    // void dfs(vector<vector<int>>&grid, int curr_row, int curr_col, vector<vector<int>>&vis, int &rows, int &cols, int &curr_area) {
    //     vis[curr_row][curr_col] = 1;
    //     curr_area++;
    //     for(int i=0; i<4; i++) {
    //         int new_row = curr_row + drow[i];
    //         int new_col = curr_col + dcol[i];

    //         if(new_row<rows && new_row>=0 && new_col<cols && new_col>=0 && grid[new_row][new_col]==1 && !vis[new_row][new_col]) {
    //             dfs(grid,new_row, new_col, vis, rows, cols, curr_area);
    //         }
    //     }
    // }

      void bfs(vector<vector<int>>&grid, int curr_row, int curr_col, vector<vector<int>>&vis, int &rows, int &cols, int &curr_area) {
        queue<pair<int,int>>q;
        q.push({curr_row, curr_col});
        vis[curr_row][curr_col]=1;
        while(!q.empty()) {
            pair<int,int>curr = q.front();
            curr_area++;
            int curr_x = curr.first, curr_y = curr.second;
            vis[curr_x][curr_y]=1;
            q.pop();
            for(int i=0; i<4; i++) {
            int new_row = curr_x + drow[i];
            int new_col = curr_y + dcol[i];

            if(new_row<rows && new_row>=0 && new_col<cols && new_col>=0 && grid[new_row][new_col]==1 && !vis[new_row][new_col]) {
                q.push({new_row, new_col});
                vis[new_row][new_col]=1;
            }
        }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>>vis(rows,vector<int>(cols, 0));
        int maxArea = 0;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j]==1 && !vis[i][j]) {
                    int curr_area = 0;
                    bfs(grid, i, j, vis, rows, cols, curr_area);
                    maxArea = max(maxArea, curr_area);
                }
            }
        }

        return maxArea;
    }
};
