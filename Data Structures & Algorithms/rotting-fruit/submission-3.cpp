class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int max_time = 0;
        vector<vector<int>>time(rows,vector<int>(cols,INT_MAX));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j]==2) {
                    q.push({{i,j},0});
                    time[i][j]=0;
                }
            }
        }

        while(!q.empty()) {
            pair<pair<int,int>,int>fro = q.front();
            q.pop();
            int x = fro.first.first, y = fro.first.second, ttr = fro.second;
            for(int i=0; i<4; i++) {
                int nx = x+dr[i], ny = y+dc[i];
                if(nx>=0 && nx<rows && ny>=0 && ny<cols && grid[nx][ny]==1) {
                    if(ttr+1<time[nx][ny]) {
                        time[nx][ny]=ttr+1;
                        max_time = max(max_time,time[nx][ny]);
                        q.push({{nx,ny},time[nx][ny]});
                    }
                }
            }
        }
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j]==1 && time[i][j]==INT_MAX)
                    return -1;
            }
        }
        return max_time;
    }
};
