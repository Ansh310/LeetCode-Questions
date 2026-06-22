class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int ans = 10000; int n = text.size();

        int freq[5] = {0, 0, 0, 0, 0};

        for(int i = 0; i < n; i++) {
            if(text[i] == 'b') freq[0]++;
            if(text[i] == 'a') freq[1]++;
            if(text[i] == 'l') freq[2]++;
            if(text[i] == 'o') freq[3]++;
            if(text[i] == 'n') freq[4]++;
        }

        freq[2] /= 2;
        freq[3] /= 2;

        for(int i = 0; i < 5; i++) ans = min(ans, freq[i]);

        return ans;



    }
};