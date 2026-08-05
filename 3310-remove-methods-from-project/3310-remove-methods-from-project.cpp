class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);

        for (auto &e : invocations) {
            adj[e[0]].push_back(e[1]);
        }

        vector<bool> vis(n, false);
        vector<bool> group(n, false);

        queue<int> q;
        q.push(k);
        vis[k] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            group[u] = true;

            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (!group[i]) {
                for (int v : adj[i]) {
                    if (group[v]) {
                        vector<int> ans;
                        for (int j = 0; j < n; j++)
                            ans.push_back(j);
                        return ans;
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!group[i])
                ans.push_back(i);
        }

        return ans;
    }
};