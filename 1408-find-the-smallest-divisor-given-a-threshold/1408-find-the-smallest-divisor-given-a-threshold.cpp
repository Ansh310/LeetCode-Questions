class Solution {
public:
    bool check(vector<int>& nums, int threshold, int mid, int n) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += ceil(nums[i] / (float)mid);
        }
        return sum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size(), st = 1, end = 1;

        for(int i = 0; i < n; i++) end = max(end, nums[i]);

        while(st < end) {
            int mid = st + (end - st) / 2;

            if(check(nums, threshold, mid, n)) end = mid;

            else st = mid + 1;
        }

        return end;

    }
};