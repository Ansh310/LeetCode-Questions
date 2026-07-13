class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int cnt1 = 0, cnt2 = 0;

        int low1 = low, high1 = high;

        while (low1) {
            low1 /= 10;
            cnt1++;
        }

        while (high1) {
            high1 /= 10;
            cnt2++;
        }

        vector<int> ans;

        for (int len = cnt1; len <= cnt2; len++) {
            for (int start = 1; start <= 10 - len; start++) {
                int num = 0;
                for (int k = start; k < start + len; k++) {
                    num = num * 10 + k;
                }

                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        return ans;
    }
};