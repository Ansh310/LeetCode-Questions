class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int total = 0, num = 1;
        for(int week = 1; week <= weeks; week++) {
            total += 7 * num + 21;
            num = num + 1;
        }

        int rem_days = n % 7;

        for(int day = 1; day <= rem_days; day++) {
            total += num;
            num += 1;
        }

        return total;
    }
};