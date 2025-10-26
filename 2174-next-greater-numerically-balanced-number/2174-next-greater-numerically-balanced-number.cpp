class Solution {
public:
    bool isBalanced(int freq_count[10]) {
        for(int d = 1; d <= 7; d++) {
            if(freq_count[d] != 0 && freq_count[d] != d) return false;
        }
        return true;
    }

    void generate_all_balanced_nos(int num, int freq_count[10], vector<int>& balanced_numbers, int n) {
        if(num > n && isBalanced(freq_count)) {
            balanced_numbers.push_back(num);
        }

        if(num > 1224444) return;

        for(int d = 1; d <= 7; d++) {
            if(freq_count[d] < d) {
                freq_count[d]++;
                generate_all_balanced_nos(num * 10 + d, freq_count, balanced_numbers, n);
                freq_count[d]--;
            }
        }
    }
    int nextBeautifulNumber(int n) {
        vector<int> balanced_numbers;

        int freq_count[10] = {0};

        generate_all_balanced_nos(0, freq_count, balanced_numbers, n);

        sort(balanced_numbers.begin(), balanced_numbers.end());

        return balanced_numbers.size() > 0  ? balanced_numbers[0] : -1;
    }
};