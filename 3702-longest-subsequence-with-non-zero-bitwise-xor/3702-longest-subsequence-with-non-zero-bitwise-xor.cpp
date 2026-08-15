class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int resultXor = 0;
        bool allZeroes = true;

        for(int &x : nums) {
            resultXor = (resultXor ^ x);

            if(x != 0) allZeroes = false;
        }

        if(allZeroes) return 0;

        if(resultXor == 0) return n - 1;

        return n;
    }
};