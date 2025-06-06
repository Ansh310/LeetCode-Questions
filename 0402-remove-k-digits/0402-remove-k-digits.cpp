class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string res = "";
        stack<char> s;

        for(int i = 0; i < n; i++) {
            while(!s.empty() && k > 0 && (num[i]) < (s.top())) {
                s.pop();
                k--;
            }
            s.push(num[i]);
        }

        if(s.empty()) return "0";

        while(k > 0) {
            s.pop();
            k--;
        }

        while(!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }

        while(res.size() > 0 && res.back() == '0') res.pop_back();

        if(res.empty()) return "0";

        reverse(res.begin(), res.end());

        return res;
    }
};