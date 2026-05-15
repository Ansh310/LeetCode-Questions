class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0, end = nums.size() - 1;

        if(nums[end] >= nums[st]) return nums[st];

        while(st < end) {
            int mid = st + ((end - st) / 2);
            if(mid  - 1 >= 0 && nums[mid - 1] > nums[mid]) return nums[mid];
            if(nums[mid] <= nums[end]) {
                end = mid - 1;
            }
            else st = mid + 1;
        }
        return nums[st];
    }
};