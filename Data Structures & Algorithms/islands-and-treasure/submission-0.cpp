class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        //we need to find the nearest distances from treasures to each land cell
        queue<pair<pair<int,int>,int>>q; 
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j]==0) {
                    q.push({{i,j},0});
                }
            }
        }
        //perform multi-source bfs
        while(!q.empty()) {
            pair<pair<int,int>,int>fro = q.front();
            q.pop();
            int x = fro.first.first, y = fro.first.second, curr_dist = fro.second;
            for(int i=0; i<4; i++) {
                int nx = x+dr[i], ny = y+dc[i];
                if(nx>=0 && nx<rows && ny>=0 && ny<cols && grid[nx][ny]!=-1 && grid[nx][ny]!=0) {
                    if(curr_dist+1<grid[nx][ny]) {
                        grid[nx][ny]=curr_dist+1;
                        q.push({{nx,ny},grid[nx][ny]});
                    }
                }
            }
        }
    }
};
