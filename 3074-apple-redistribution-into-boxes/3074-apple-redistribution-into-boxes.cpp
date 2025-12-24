class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size(), sum = 0, it = capacity.size() - 1;
        sort(capacity.begin(), capacity.end());

        for(int i = 0; i < n; i++) {
            sum = sum + apple[i];
        }

        
        while(sum > 0) {
            sum = sum - capacity[it];
            it--;
        }

        return capacity.size() - it - 1;
    }
};