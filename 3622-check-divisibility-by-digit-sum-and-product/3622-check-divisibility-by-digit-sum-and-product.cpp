class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prod = 1;
        int temp = n;

        while(temp) {
            int d = temp % 10;
            sum = sum + d;
            prod = prod * d;
            temp = temp / 10;
        }

        int sum2 = sum + prod;

        return !(n % sum2);
    }
};