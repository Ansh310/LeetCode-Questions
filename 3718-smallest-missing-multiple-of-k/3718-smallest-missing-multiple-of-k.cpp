class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> store;

        for(int i = 0; i < nums.size(); i++) {
            store.insert(nums[i]);
        }

        int adder = k;

        while(true) {
            if(store.find(k) == store.end()) break;
            k = k + adder;
        }

        return k;
    }
};