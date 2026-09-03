class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        int minOdd = INT_MAX, minEven = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(nums1[i] % 2 == 0) {
                minEven = min(minEven, nums1[i]);
            }
            else {
                minOdd = min(minOdd, nums1[i]);
            }
        }

        if(minOdd == INT_MAX || minEven == INT_MAX) return true;

        if(minEven > minOdd) return true;

        return false;

    }
};