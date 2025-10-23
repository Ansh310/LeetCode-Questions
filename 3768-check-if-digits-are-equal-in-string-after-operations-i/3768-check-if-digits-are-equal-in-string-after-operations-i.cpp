class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();

        while(n > 2) {
            
            for(int i = 0; i < n - 1; i++) {
                int digit1 = s[i] - '0';
                int digit2 = s[i + 1] - '0';
                int sum = (digit1 + digit2) % 10;
                char ch = sum + '0';
                s[i] = ch;
            }

            s[n - 1] = '\0';
            n--;
        }

        return s[0] == s[1];
    }
};