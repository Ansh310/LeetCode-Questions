class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(); int cnt = 0; int sum = 0;

        unordered_map<int, int> sumFreqMap;
        sumFreqMap[0] = 1;

        for(int i = 0; i < n; i++) {
            sum += nums[i];

            cnt += sumFreqMap[sum - goal];

            sumFreqMap[sum]++;
        }
           

        return cnt;
    }
};