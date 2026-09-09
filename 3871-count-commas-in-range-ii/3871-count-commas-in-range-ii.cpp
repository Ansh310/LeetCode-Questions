class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;
        long long start = 1000;
        long long commas = 1;

        while(start <= n) {
            long long end = start * 1000 - 1;

            if(end > n) end = n;

            total += (end - start + 1) * commas;

            start *= 1000;
            commas++;
        }
        return total;
    }
};