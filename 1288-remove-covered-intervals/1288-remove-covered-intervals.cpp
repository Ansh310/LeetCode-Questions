class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        vector<vector<int>> ans;

        vector<int> lastInterval = intervals[0];

        ans.push_back(lastInterval);

        for(int i = 1; i < n; i++) {
            if(intervals[i][1] <= lastInterval[1] || intervals[i][0] == lastInterval[0]) {
                lastInterval[0] = lastInterval[0];
                lastInterval[1] = max(intervals[i][1], lastInterval[1]);
                ans.back()[0] = lastInterval[0];
                ans.back()[1] = lastInterval[1];
            }
            else {
                lastInterval[0] = intervals[i][0];
                lastInterval[1] = intervals[i][1];
                ans.push_back(lastInterval); 
            }
            
        }

        return ans.size();
        
    }
};