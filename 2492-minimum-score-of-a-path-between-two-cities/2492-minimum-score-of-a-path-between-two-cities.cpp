class Solution {
public:
    void dfs(vector<vector<pair<int, int>>>& adj, vector<int>& vis, int node, int& ans) {
        vis[node] = 1;

        for(auto neighbour : adj[node]) {
            ans = min(ans, neighbour.second);
            if(!vis[neighbour.first]) {
                dfs(adj, vis, neighbour.first, ans);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for(int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        vector<int> visited(n + 1, 0);
        int answer = INT_MAX;

        dfs(adj, visited, 1, answer);

        return answer;
    }
};