class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    void dfs(vector<vector<char>>& board,
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
               board[nr][nc]=='O') {
                dfs(board, vis, nr, nc, rows, cols);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        for(int i=0; i<rows; i++) {
            if(board[i][0]=='O')
            dfs(board,vis,i,0,rows,cols);
        }
        for(int i=0; i<rows; i++) {
            if(board[i][cols-1]=='O')
            dfs(board,vis,i,cols-1,rows,cols);
        }
        for(int i=0; i<cols; i++) {
            if(board[0][i]=='O')
            dfs(board,vis,0,i,rows,cols);
        }
        for(int i=0; i<cols; i++) {
            if(board[rows-1][i]=='O')
            dfs(board,vis,rows-1,i,rows,cols);
        }

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(!vis[i][j] && board[i][j]=='O')
                    board[i][j]='X';
            }
        }
    }
};
