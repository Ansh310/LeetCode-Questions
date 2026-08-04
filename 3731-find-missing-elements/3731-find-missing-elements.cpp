class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        vector<int> ans;
        int mini = 101, maxi = 0;

        for(int i = 0; i < n; i++) {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
            s.insert(nums[i]);
        }

        for(int i = mini; i <= maxi; i++) {
            if(s.find(i) == s.end()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};