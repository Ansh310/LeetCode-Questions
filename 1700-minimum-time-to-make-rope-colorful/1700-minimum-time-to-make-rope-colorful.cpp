class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size(), i = 0, total = 0;

        while(i < n) {

            int maxTime = 0;
            int sum = 0;
            while(i + 1 < n && colors[i] == colors[i + 1]) {
                maxTime = max(maxTime, neededTime[i]); sum += neededTime[i]; i++;}

            maxTime = max(maxTime, neededTime[i]); sum += neededTime[i];
            sum -= maxTime;

            total += sum;

            i++;
            


        }

        return total;
    }
};