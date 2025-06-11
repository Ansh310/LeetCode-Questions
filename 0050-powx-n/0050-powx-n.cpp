class Solution {
public:
    double Pow(double x, long int n) {
        if(x == 0) return 0;
        if(n == 0) return 1;

        double recur = Pow(x, n / 2);
        if(n % 2) return recur * recur * x;

        return recur * recur;
    }

    double myPow(double x, int n) {
        bool sign = false;
        if(n < 0) sign = true;
        
        double ans = Pow(x, n);

        return sign ? 1 / ans : ans;
    }
};