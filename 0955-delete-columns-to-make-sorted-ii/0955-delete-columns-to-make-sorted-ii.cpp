class Solution {
public:
    bool check1(vector<string>& strs, int j, int i, unordered_set<int>& indices) {
        if(i == 0) return true;
        for(int k = i - 1; k >= 0; k--) {
            if(indices.find(k) == indices.end() && strs[j - 1][k] < strs[j][k]) {
                return false;
            }
            
        }
        if(strs[j - 1][i] > strs[j][i]) return true;
        return false;
    }
    bool check(vector<string>& strs, int i, unordered_set<int>& indices) {
        for(int j = 1; j < strs.size(); j++) {
            
            if(strs[j - 1][i] > strs[j][i]) {
                if(check1(strs, j, i, indices))
                return false;

                

            }
        }
        return true;
    }

    int minDeletionSize(vector<string>& strs) {
        int i = 0;
        unordered_set<int> indices;

        while(i < strs[0].size()) {
            bool cond = check(strs, i, indices);
            if(!cond) indices.insert(i);
            i++;
        }
        return indices.size();
    }
};