class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        vector<int> freq(3, 0);
        int n = bills.size();

        for(int i = 0; i < n ; i++) {

            if(bills[i] == 10) {
                if(freq[0] == 0) return false;
                
                freq[0]--; freq[1]++;
            }

            else if(bills[i] == 20) {
                if((freq[0] == 0 || freq[1] == 0) && freq[0] < 3) return false;

                if(freq[1] > 0) {freq[0]--; freq[1]--;} else {freq[0] -= 3;} freq[2]++;
            }

            else freq[0]++;
        }

        return true;
        
    }
};