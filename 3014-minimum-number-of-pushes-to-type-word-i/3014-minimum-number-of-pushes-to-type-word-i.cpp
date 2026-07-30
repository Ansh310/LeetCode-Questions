class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        if(n <= 8) return n;

        if(n <= 16) return 8 + 2 * (n - 8);

        if(n <= 24) return 3 * 8 + 3 * (n - 16);

        return 6 * 8 + 4 * (n - 24);
    }
};