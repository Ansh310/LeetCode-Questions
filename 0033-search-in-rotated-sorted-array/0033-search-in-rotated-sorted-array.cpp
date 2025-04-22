class Solution {
public:
    int binary_search(vector<int>& nums, int st, int end, int target) {

        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(nums[mid] == target) return mid;

            else if(nums[mid] > target) end = mid - 1;

            else st = mid + 1;
        }
        return -1;
    }

    int find(vector<int>& nums, int n) {
        int st = 0, end = n - 1;

        while(st < end) {
            int mid = st + (end - st) / 2;

            if(nums[mid] > nums[n - 1]) st = mid + 1;

            else end = mid;
        }
        return end;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int mini = find(nums, n);

        if(target <= nums[n - 1]) return binary_search(nums, mini, n - 1, target);

        return binary_search(nums, 0, mini - 1, target);
    }
};