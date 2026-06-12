class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0; //source
        for(int i=0; i<times.size(); i++) { //build the adjacency matrix
            int u = times[i][0], v = times[i][1], tm = times[i][2];
            adj[u].push_back({v,tm});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k}); //pq will contain {time,node}

        while(!pq.empty()) {
            pair<int,int>curr = pq.top();
            pq.pop();
            int time_for_node = curr.first, node = curr.second;
            if(time_for_node>dist[node]) continue;

            for(auto i: adj[node]) {
                int neighbor = i.first, time_for_neigh = i.second;
                if(time_for_node+time_for_neigh<dist[neighbor]) {
                    dist[neighbor] = time_for_node+time_for_neigh;
                    pq.push({dist[neighbor],neighbor});
                }
            }
        }
        int ans = 0;
        for(int i=1; i<=n; i++) {
            if(dist[i]==INT_MAX)
                return -1;
            else ans = max(ans, dist[i]);
        }
        return ans;
    }
};
