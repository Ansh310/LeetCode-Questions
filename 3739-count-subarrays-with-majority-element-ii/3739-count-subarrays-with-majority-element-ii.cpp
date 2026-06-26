class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        long long result = 0;
        long long vlp = 0;
        long long currSum = 0;
        mp[0] = 1;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                vlp += mp[currSum];
                currSum += 1;
            }
            else {
                currSum -= 1;
                vlp -= mp[currSum];

            }
            mp[currSum]++;         
            result += vlp;
        }

        return result;
    }
};