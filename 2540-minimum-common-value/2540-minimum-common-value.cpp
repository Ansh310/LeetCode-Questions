class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int pt1= 0, pt2 = 0, n = nums1.size(), m = nums2.size();

        while(pt1 < n && pt2 < m) {
            while(pt1 < n && nums1[pt1] < nums2[pt2]) pt1++;

            if (pt1 < n && nums1[pt1] == nums2[pt2]) return nums1[pt1];

            pt2++;
        }

        return -1;
    }
};