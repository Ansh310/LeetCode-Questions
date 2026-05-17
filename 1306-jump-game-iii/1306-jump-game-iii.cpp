class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, 0);
        queue<int> q;

        q.push(start);
        vis[start] = 1;

        while(!q.empty()){
            auto front = q.front(); 
            q.pop();

            if(arr[front] == 0) return true;

            if(front + arr[front] < n && vis[front + arr[front]] == 0) {q.push(front + arr[front]); 
            vis[front + arr[front]] = 1;}
            if(front - arr[front] >= 0 && vis[front - arr[front]] == 0) {q.push(front - arr[front]); 
            vis[front - arr[front]] = 1;}
        }

        return false;
    }
};