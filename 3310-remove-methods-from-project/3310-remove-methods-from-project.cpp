class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);

        for(int i = 0; i < invocations.size(); i++) {
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }

        unordered_set<int> group;
        vector<bool> vis(n, false);
        bool flag = true;

        queue<int> q;
        q.push(k);

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                int front = q.front();
                q.pop();

                group.insert(front);
                vis[front] = true;

                for(auto x : adj[front]) {
                    if(!vis[x]) {
                        q.push(x);
                    }
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                for(auto x : adj[i]) {
                    if(group.find(x) != group.end()) {
                        flag = false;
                        break;
                    }
                }
            }
        }

        vector<int> ans;

        if(flag) {
            for(int i = 0; i < n; i++) {
                if(group.find(i) == group.end()) {
                    ans.push_back(i);
                }
            }
        } else {
            for(int i = 0; i < n; i++) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};