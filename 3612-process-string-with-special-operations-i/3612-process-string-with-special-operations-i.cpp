class Solution {
public:
    string processStr(string s) {
        int n = s.size();
        string result = "";

        for(int i = 0; i < n; i++) {
            if(s[i] >= 'a' && s[i] <= 'z') {result += s[i];}

            if(s[i] == '*') {result = result.substr(0, result.size() - 1);}

            if(s[i] == '%') {reverse(result.begin(), result.end());}

            if(s[i] == '#') result = result + result;
        }

        return result;
    }
};