class Solution {
public:
    int calc(int x) {
        int product = 1;
        while(x) {
            int d = x % 10;
            product = product * d;
            if(product == 0) return 0;
            x /= 10;
        }
        return product;
    }

    int smallestNumber(int n, int t) {
        int product = 1;
        int x  = n;

      
        if(product % t == 0) return x;
        while(product % t != 0) {
            product = calc(x); 
            x = x + 1;    
        }

        return x - 1;
    }
};