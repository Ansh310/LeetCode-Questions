class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size(), dist = 1000;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    if(nums[i] == nums[j] && nums[j] == nums[k]) {
                        dist = min(dist, abs(i - j) + abs(j - k) + abs(k - i));
                    }
                }
            }
        }
        return dist == 1000 ? -1 : dist;
    }
};