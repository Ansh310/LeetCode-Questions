class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> vec = nums;

        //sort the vector
        sort(vec.begin(), vec.end());

        //Build Groups
        int groupNum = 0;
        unordered_map<int, int> numToGroup;
        numToGroup[vec[0]] = groupNum;

        unordered_map<int, list<int>> groupToList; //we can use deque also...

        groupToList[groupNum].push_back(vec[0]);

        for(int i = 1; i < n; i++) {
            if(abs(vec[i] - vec[i - 1]) > limit) {
                groupNum += 1;

            }
            numToGroup[vec[i]] = groupNum;
            groupToList[groupNum].push_back(vec[i]);
        }

        //Build the answer
        vector<int> result(n);
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            int group = numToGroup[num];

            result[i] = *(groupToList[group].begin());
            groupToList[group].pop_front();

        }

        return result;

    }
};