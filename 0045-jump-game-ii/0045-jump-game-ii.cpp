class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(); 
        int left = 0, right = 0, jumps = 0;

        while(right < n - 1) {
            int farthest = 0;

            for(int j = left; j <= right; j++) {
                farthest = max(farthest, j + nums[j]);
            }

            left = right + 1;
            right = farthest;
            jumps++;
        }
        return jumps;
    }
};