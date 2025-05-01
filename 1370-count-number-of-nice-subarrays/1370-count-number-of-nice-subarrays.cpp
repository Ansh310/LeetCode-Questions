class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), st = 0, ans = 0, cnt = 0, gap = 0;
        
        for(int end = 0; end < n; end++) {
            if(nums[end] & 1) cnt++;

            if(cnt == k) {
                gap = 0;

                while(cnt == k) {
                    cnt -= (nums[st] & 1);
                    gap++;
                    st++;
                }
            }
            ans += gap;
        }
        return ans;
    }
};