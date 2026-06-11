class Solution {
public:
    void dfs(vector<int>adj[], vector<int>&vis, int curr) {
        vis[curr]=1;
        for(auto i: adj[curr]) {
            if(!vis[i])
                dfs(adj,vis,i); 
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int>vis(n);
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int ans=0;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                ans++;
                dfs(adj,vis,i);
            }
        }
        return ans;
    }
};
