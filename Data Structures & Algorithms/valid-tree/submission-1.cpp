class Solution {
public:
    bool dfs(vector<int>adj[], vector<int>&vis, int curr, int parent) {
        vis[curr]=1;
        for(auto i: adj[curr]) {
            if(!vis[i]) {
                if(dfs(adj,vis,i,curr)) 
                    return true;
            }
            else if(i!=parent) {
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int>vis(n);
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        bool single = true;
        if(dfs(adj,vis,0,-1)) return false; //if there is a cycle, return false
        else { //if there isn't a cycle, but multiple components, return false;
            for(int i=0; i<n; i++) {
                if(vis[i]==0) {
                    single=false;
                    break;
                }
            }
            if(!single) return false;
        }
        return true;
    }
};
