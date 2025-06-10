class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), st = 0, end = 0, counter = t.size(), minSt = 0, minLen = INT_MAX;
        unordered_map<char, int> m;

        for(auto ch : t) {
            m[ch]++;
        }

        while(end < n) {
            if(m[s[end]] > 0) counter--;

            m[s[end]]--;
            end++;

            while(counter == 0) {
                if(end - st < minLen) {
                    minSt = st;
                    minLen = end - st;
                }
                m[s[st]]++;

                if(m[s[st]] > 0) counter++;

                st++;
            }
        }

        if(minLen != INT_MAX) return s.substr(minSt, minLen);
        return "";
        
    }
};