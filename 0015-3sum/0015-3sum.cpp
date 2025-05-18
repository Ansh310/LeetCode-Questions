class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        for(int i = 0; i < n - 2; i++) {
            if(i > 0 && nums[i - 1] == nums[i]) continue;

            int s = i + 1, e = n - 1, target = -nums[i];

            while(s < e) {
                if(nums[s] + nums[e] == target) {
                    ans.push_back({nums[s++], nums[e--], nums[i]});
                }
                else if(nums[s] + nums[e] > target) e--;

                else s++;

                while(s > i + 1 && s < e && nums[s] == nums[s - 1]) s++;

                while(e < n - 1 && s < e && nums[e + 1] == nums[e]) e--;
            }

        }
        return ans;
    }
};