class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> map(10, 0);

        for(int i = 0; i < n; i++) map[digits[i]]++;

        int total = 0;

        for(int i = 1; i <= 9; i++) {
            if(map[i] == 0) continue;
            map[i]--;

            for(int j = 0; j <= 9; j++) {
                if(map[j] == 0) continue;
                map[j]--;

                for(int k = 0; k <= 8; k += 2) {
                    if(map[k] == 0) continue;
                    total++;
                    
                }
                map[j]++;
                
            }
            map[i]++;
        }

        return total;
        
    }
};