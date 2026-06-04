class Solution {
public:
    int calc_score(int& num) {
        if(num < 100) return 0;

        int total = 0;

        string str = to_string(num);

        int len = str.size();

        for(int i = 1; i < len - 1; i++) {
            if((str[i] < str[i - 1] && str[i] < str[i + 1]) || (str[i] > str[i - 1] && str[i] > str[i + 1])) {
                total++;
            }
        }
        return total;
    }

    int totalWaviness(int num1, int num2) {
        int score = 0;
        for(int num = num1; num <= num2; num++) {
            score += calc_score(num);
        }
        return score;
    }
};