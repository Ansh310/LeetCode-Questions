class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int fl = INT_MIN, sl = INT_MIN, tl = INT_MIN, top1 = INT_MAX, top2 = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) {
                if(nums[i] < top1) {
                    top2 = top1;
                    top1 = nums[i];
                }
                else if(nums[i] < top2) {
                    top2 = nums[i];
                }
            }
            if(nums[i] > fl) {
                tl = sl;
                sl = fl;
                fl = nums[i];
            }
            else if(nums[i] > sl) {
                tl = sl;
                sl = nums[i];
            }
            else if(nums[i] > tl) tl = nums[i];
        }

        if(fl < 0) return fl * sl * tl;

        if(top1 < INT_MAX && top2 < INT_MAX) {
            return max(top1 * top2 * fl, fl * sl * tl);
        }

        return fl * sl * tl;
    }
};