class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal;

        if(ans == 0) return 0;

        int cnt = 0, end = (log(ans) / log(2));

        for(int i = 0; i <= end; i++) {
            if(ans & (1 << i)) cnt++;
        }

        return cnt;
    }
};