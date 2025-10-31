class Solution {
public:
    int smallestNumber(int n) {
        int maxPosSetBit = 0;

        for(int i = 0; i < 10; i++) {
            if((n >> i) & 1) maxPosSetBit = i;
        }

        return pow(2, (maxPosSetBit + 1)) - 1;
    }
};