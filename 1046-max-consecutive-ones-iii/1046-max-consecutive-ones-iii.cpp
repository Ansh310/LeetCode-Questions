class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int st = 0, end = 0;

        while(end < n) {
            if(nums[end] == 0) k--;

            if(k < 0) {
                if(nums[st] == 0) k++;

                st++;
            }

            end++;
        }
            

        return end - st;
    }
};