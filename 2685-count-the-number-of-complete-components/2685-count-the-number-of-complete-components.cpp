class Solution {
public:
    void buildGraph(vector<vector<int>>& adj, vector<vector<int>>& edges, int n) {
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
    }

    void dfs(vector<vector<int>>& adj, vector<int>& vis, int &cnt_v, int &cnt_e, int node, int &deg) {
        vis[node] = 1;
        cnt_v++;

        for(auto neighbour : adj[node]) {
            deg++;
            if(!vis[neighbour]) {
                
                dfs(adj, vis, cnt_v, cnt_e, neighbour, deg);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        buildGraph(adj, edges, n);

        vector<int> vis(n, 0);
        
        int count_vertices = 0, count_edges = 0, degree = 0;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                count_edges = degree / 2;
                if(i != 0 && (count_edges == (((count_vertices) * (count_vertices - 1)) / 2))) ans++;
                count_vertices = count_edges = degree = 0;
                dfs(adj, vis, count_vertices, count_edges, i, degree);
            }
        }
        count_edges = degree / 2;
        if(count_edges == ((count_vertices) * (count_vertices - 1)) / 2) ans++;
        return ans;
    }
};