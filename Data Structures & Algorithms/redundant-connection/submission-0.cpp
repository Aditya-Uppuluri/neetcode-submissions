class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        int ru = rank[pu];
        int rv = rank[pv];

        if (ru < rv) {
            parent[pu] = pv;
        }
        else if (ru > rv) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (findParent(u) == findParent(v)) {
                return {u, v};
            }

            unionByRank(u, v);
        }

        return {};
    }
};