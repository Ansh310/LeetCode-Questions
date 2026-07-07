class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0) return 0;

        long long ans = 0;
        int cnt = 0;
        int sum = 0;


        while(n) {
            int d = n % 10;
            if(d) {
                ans = d * pow(10, cnt) + ans;
                cnt++;
                sum += d;
            }
            n /= 10;
            
        }

        return ans * sum;
    }
};