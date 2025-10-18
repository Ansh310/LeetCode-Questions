class Solution {
public:

    int calc_digi_sum(int num) {
        int sum = 0;
        while(num > 0) {
            int digit = num % 10;
            sum += digit;
            num = num / 10;
        }
        return sum;
    }

    int differenceOfSum(vector<int>& nums) {
        
        int n = nums.size(), sum = 0, digit_sum = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];

            digit_sum += calc_digi_sum(nums[i]);
        }

        return abs(sum - digit_sum);
    }
};