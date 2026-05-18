class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(); int steps = 0;

        vector<int> vis(n, 0);
        queue<int> q;

        unordered_map<int, vector<int>> indices;

        for(int i = 0; i < n; i++) indices[arr[i]].push_back(i);

        q.push(0); vis[0] = 1;

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                int front = q.front();
                q.pop();

                if(front == n - 1) return steps;

                if(front - 1 >= 0 && vis[front - 1] == 0) {
                    q.push(front - 1);
                    vis[front - 1] = 0;
                }

                if(front + 1 < n && vis[front + 1] == 0) {
                    q.push(front + 1);
                    vis[front + 1] = 0;
                }

                for(auto idx : indices[arr[front]]) {
                    if(vis[idx] == 0) {
                        q.push(idx);
                        vis[idx] = 1;
                    }
                }
                indices[arr[front]].clear();
            }
            steps++;
        }
        return -1;

    }
};