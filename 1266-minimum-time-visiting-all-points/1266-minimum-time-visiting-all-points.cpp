class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();

        int sum = 0;

        for(int i = 0; i < n - 1; i++) {
            int diff1 = abs(points[i + 1][0] - points[i][0]);
            int diff2 = abs(points[i + 1][1] - points[i][1]);

            sum += max(diff1, diff2);
        }
        return sum;
    }
};