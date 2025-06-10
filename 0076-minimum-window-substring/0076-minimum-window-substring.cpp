class Solution {
public:
    bool check(unordered_map<char, int>& s1, unordered_map<char, int>& s2) {
        for(auto pair : s1) {
            if(s1[pair.first] > s2[pair.first]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int n = s.size(), m = t.size(), st = 0, mini = INT_MAX, ans_st = 0, ans_end = -1;
        unordered_map<char, int> s1, s2;
        
        for(int i = 0; i < m; i++) s1[t[i]]++;

        for(int i = 0; i < n; i++) {
            s2[s[i]]++;

            while(check(s1, s2)) {
                if(i - st + 1 < mini) {
                    ans_st = st;
                    ans_end = i;
                    mini = i - st + 1;
                }
                s2[s[st]]--;
                st++;
            }
       }

       return s.substr(ans_st, ans_end - ans_st + 1);
    }
};