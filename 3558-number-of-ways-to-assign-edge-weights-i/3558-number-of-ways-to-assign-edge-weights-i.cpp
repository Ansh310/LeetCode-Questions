class Solution {
public:
    int max_level = 0;
    int qpow(int x, int y) {
        int res = 1;

        for(; y; y >>= 1) {
            if(y & 1) {
                res = 1ll * res * x % 1000000007;
            }

            x = 1ll * x * x % 1000000007;
        }
        return res;
    }

    void dfs(vector<vector<int>>& adj, vector<int>& vis, int node, int &max_level, int level) {
        if(level > max_level) max_level = level;

        vis[node] = 1;

        for(auto neighbour : adj[node]) {
            if(vis[neighbour] == 0)
               dfs(adj, vis, neighbour, max_level, level + 1);
        }
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);
        vector<int> vis(n + 1, 0);

        for(int i = 0; i < n - 1; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        dfs(adj, vis, 1, max_level, 0);

        return qpow(2, max_level - 1);
    }
};