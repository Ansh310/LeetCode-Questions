class Solution {
public:
    bool check(vector<int>& f) {
        if(f[0] && f[1] && f[2]) return true;
        return false;
    }

    int numberOfSubstrings(string s) {
        int count = 0;
        vector<int> f(3, 0);
        int n = s.size();
        int st = 0, end = 0;

        while(end < n) {
            f[s[end] - 'a']++;

            while(check(f)) {
                count += n - end;
                f[s[st] - 'a']--;
                st++;
            }
            end++;
        }
        return count;
    }
};