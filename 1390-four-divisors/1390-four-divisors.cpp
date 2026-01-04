class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();

        int total_sum = 0;

        for(int i = 0; i < n; i++) {
            int sum = 0, count = 0;

            for(int j = 1; j * j <= nums[i]; j++) {
                if(nums[i] % j == 0) {if(j * j != nums[i]) count += 2; else count++; sum += j + (nums[i] / j);}
            }
            if(count == 4) total_sum += sum;

        }
        return total_sum;
    }
};