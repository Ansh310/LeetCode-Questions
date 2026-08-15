class Solution {
public:
    

    int maximumLengthSubstring(string s) {
        int n = s.size();

        vector<int> freq1(26, 0);

        for(int i = 0; i < n; i++) {
            freq1[s[i] - 'a']++;
        }

        vector<int> freq2(26, 0);
        int ans = 0, i = 0, st = 0;

        while(i < n && st < n) {
            while(i < n && freq2[s[i] - 'a'] < 2) {
                freq2[s[i] - 'a']++;
                i++;
            }

            ans = max(ans, i - st);

            freq2[s[st] - 'a']--;
            st++;
        }

        return ans;
    }
};