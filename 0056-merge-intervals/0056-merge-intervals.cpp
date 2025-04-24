class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        vector<vector<int>> ans;

        int i = 0;

        while(i < n) {
            int st = intervals[i][0], endi = intervals[i][1];
            while(i + 1 < n && endi >= intervals[i + 1][0]) {

                endi = max(endi, intervals[i + 1][1]);
                i++;
                
            }

            ans.push_back({st, endi});
            i++;
        }
        
        return ans;
    }
};