class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        int i = 0, j = 0, st = 0;
        unordered_map<int, int> farthestNode;

        while(i < n) {

            while(j < n && nums[j] - nums[i] <= maxDiff) j++;

            i++;

            if(i == j) {
                for(int k = st; k < i; k++) {
                    farthestNode[k] = i - 1;
                }
                st = i;
            }
        }

        if(i == j) {
            for(int k = st; k < i; k++) {
                farthestNode[k] = i - 1;
            }
            st = i;
        }

        int q = queries.size();
        vector<bool> ans(q, false);

        for(int i = 0; i < q; i++) {
            int node1 = queries[i][0];
            int node2 = queries[i][1];

            if(node1 < node2) {
                if(farthestNode[node1] >= farthestNode[node2]) ans[i] = true;
            }
            else {
                if(farthestNode[node2] >= farthestNode[node1]) ans[i] = true;
            }
        }
        return ans;
    }
};