class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> idx;

        int n = nums1.size(), m = nums2.size();

        for(int i = 0; i < m; i++) idx[nums2[i]] = i;

        stack<int> st;

        for(int i = m - 1; i >= 0; i--) {
            while(!st.empty() && nums2[i] >= st.top()) st.pop();
            int temp = nums2[i];

            if(st.empty()) nums2[i] = -1;

            else nums2[i] = st.top();
            st.push(temp);
        }

        vector<int> nge(n);

        for(int i = 0; i < n; i++) {
            nge[i] = nums2[idx[nums1[i]]];
        }
        return nge;
    }
};