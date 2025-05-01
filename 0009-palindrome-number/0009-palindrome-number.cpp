class Solution {
public:
    bool isPalindrome(int x) {

        if(x < 0 || (x != 0 && (x % 10) == 0)) return false;

        int rev = 0, temp = x;

        while(temp > rev) {
            rev = rev * 10 + (temp % 10);
            temp /= 10;
        }

        return (temp == rev) || (temp == rev / 10);
    }
};