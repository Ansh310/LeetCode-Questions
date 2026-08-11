class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        bool done = false;
        unordered_set<int> s;
        s.insert(nums[0]);

        for(int i = 1; i < n; i++) {
            if(!done && nums[i] == nums[i - 1] + 1) {
                ans += nums[i];
            }
            else done = true;
            s.insert(nums[i]);
        }


        while(s.find(ans) != s.end()) ans++;

        return ans;
    }
};