class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int curr_penalty = 0, min_penalty = 0, earliest_hour = 0;

        for(int i = 0; i < n; i++) {
            if(customers[i] == 'Y') curr_penalty--;

            else curr_penalty++;

            if(curr_penalty < min_penalty) {
                min_penalty = curr_penalty;
                earliest_hour = i + 1;
            }
        }
        return earliest_hour;
    }
};