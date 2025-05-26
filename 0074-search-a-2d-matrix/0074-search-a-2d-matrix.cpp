class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        pair<int, int> s = {0, 0}, e = {m - 1, n - 1};

        while(s.first <= e.first && s.second <= e.second) {
            pair<int, int> mid = {(s.first + e.first) / 2, (s.second + e.second) / 2};

            int r = mid.first, c = mid.second;
            if(matrix[r][c] == target) return true;

            else if(matrix[r][c] < target) {
                if(c + 1 < n) s.second = c + 1;
                else s = {r + 1, 0};
            }

            else {
                if(c - 1 >= 0) e.second = c - 1;
                else e = {r - 1, n - 1};
            }
        }

        return false;
    }
};