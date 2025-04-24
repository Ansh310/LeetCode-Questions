class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start = newInterval[0], end = newInterval[1], i = 0, n = intervals.size();
        if(n == 0) return {{start, end}};
        vector<vector<int>> ans;

        while(i < n && intervals[i][1] < start) {
            ans.push_back(intervals[i]);
            i++;
        }

        if(i < n) start = min(start, intervals[i][0]);

        while(i < n && intervals[i][0] <= end) {
            i++;
        }

        if(i > 0) end = max(end, intervals[i - 1][1]);

        ans.push_back({start, end});

        while(i < n) ans.push_back(intervals[i++]);

        return ans;
    }
};