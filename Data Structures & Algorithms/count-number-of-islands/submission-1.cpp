class Solution {
public:
    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,1,0,-1};

    // void dfs(vector<vector<char>>&grid, int curr_row, int curr_col, vector<vector<int>>&vis, int &rows, int &cols) {
    //     vis[curr_row][curr_col] = 1;
    //     for(int i=0; i<4; i++) {
    //         int new_row = curr_row + drow[i];
    //         int new_col = curr_col + dcol[i];

    //         if(new_row<rows && new_row>=0 && new_col<cols && new_col>=0 && grid[new_row][new_col]=='1' && !vis[new_row][new_col]) {
    //             dfs(grid,new_row, new_col, vis, rows, cols);
    //         }
    //     }
    // }

    void bfs(vector<vector<char>>&grid, int curr_row, int curr_col, vector<vector<int>>&vis, int &rows, int &cols) {
        queue<pair<int,int>>q;
        q.push({curr_row, curr_col});
        while(!q.empty()) {
            pair<int,int>curr = q.front();
            int curr_x = curr.first, curr_y = curr.second;
            vis[curr_x][curr_y]=1;
            q.pop();
            for(int i=0; i<4; i++) {
            int new_row = curr_x + drow[i];
            int new_col = curr_y + dcol[i];

            if(new_row<rows && new_row>=0 && new_col<cols && new_col>=0 && grid[new_row][new_col]=='1' && !vis[new_row][new_col]) {
                q.push({new_row, new_col});
            }
        }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>>vis(rows, vector<int>(cols, 0));
        int numofIslands = 0;
        //whenever we see a land that we haven't already seen while traversing, run a dfs on it.
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j]=='1' && !vis[i][j]) {
                    numofIslands++;
                    bfs(grid,i,j,vis,rows,cols);
                }
            }
        }

        return numofIslands;
    }
};
