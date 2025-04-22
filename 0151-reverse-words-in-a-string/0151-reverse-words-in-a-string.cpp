class Solution {
public:
    string reverseWords(string s) {

        reverse(s.begin(), s.end());

        string ans = "";

        int st = 0, end = 0;

        while(end < s.size()) {
            while(end < s.size() && s[end] == ' ') end++;
            st = end;
            if(end == s.size()) break;
            //cout<<end<<" ";
            if(ans != "") ans += " ";

            while(end < s.size() && s[end] != ' ') end++;
            reverse(s.begin() + st, s.begin() + end);
            ans += s.substr(st, end - st);

        }
        return ans;
        
    }
};