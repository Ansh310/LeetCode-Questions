class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> index(128, -1);
        int st = 0, cnt = 0;

        for(int i = 0; i < n; i++) {
            if(index[s[i] - '\0'] >= st)
                st = index[s[i] - '\0'] + 1;

            index[s[i] - '\0'] = i;
            cnt = max(cnt, i - st + 1);
        }
        return cnt;
    }
};