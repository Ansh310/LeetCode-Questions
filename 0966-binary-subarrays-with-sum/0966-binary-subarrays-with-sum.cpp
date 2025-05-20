class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(); int currSum = 0, prefixZeros = 0, totalCount = 0, st = 0;

        for(int end = 0; end < n; end++) {
            currSum += nums[end];

            while(st < end && (nums[st] == 0 || currSum > goal)) {
                if(nums[st] == 1) {
                    prefixZeros = 0;
                } else {
                    prefixZeros += 1;
                }

                currSum -= nums[st];
                st++;
            }

            if(currSum == goal) {
                totalCount += 1 + prefixZeros;
            }
        }
        return totalCount;
    }
};