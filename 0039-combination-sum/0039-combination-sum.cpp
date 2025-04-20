class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        vector<int> comb;

        combine(candidates, target, 0, comb, 0, output);

        return output;

    }

    void combine(vector<int>& candidates, int target, int idx, vector<int>& comb, int total, vector<vector<int>>& output) {
        if (total == target) {
            output.push_back(comb);
            return;
        }
        if (total > target || idx >= candidates.size()) {
            return;
        }
        comb.push_back(candidates.at(idx));
        combine(candidates, target, idx, comb, total + candidates.at(idx), output);
        comb.pop_back();
        combine(candidates, target, idx + 1, comb, total, output);
        return;
    }


};