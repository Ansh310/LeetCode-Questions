class Solution {
public:
    bool isIsomorphic(string s, string t) {

        char map[128] = {'\0'};
        bool used[128] = {false};

        if(s.size() != t.size()) return false;

        for(int i = 0; i < s.size(); i++) {
            if(map[s[i] - '\0'] != '\0' 
            && map[s[i] - '\0'] != t[i]) return false;

            else if(map[s[i] - '\0'] == '\0' && used[t[i] - '\0']) return false;

            map[s[i] - '\0'] = t[i];
            used[t[i] - '\0'] = true;
        }

        return true;
    }
};