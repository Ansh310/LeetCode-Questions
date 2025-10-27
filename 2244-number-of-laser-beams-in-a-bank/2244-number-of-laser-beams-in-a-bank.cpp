class Solution {
public:
    int atleast_ones(string row, int n) {
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(row[i] == '1') count++;
        }

        return count;
    }

    int numberOfBeams(vector<string>& bank) {
        int m = bank.size();
        int n = bank[0].size();
        
        int total_beams = 0, prev_row_ones = 0;

        for(int i = 0; i < m; i++) {
            int count_ones = atleast_ones(bank[i], n);
            if(count_ones > 0) {
                
                total_beams += count_ones * prev_row_ones;
                prev_row_ones = count_ones;
                
            }
        }

        return total_beams;
    }
};