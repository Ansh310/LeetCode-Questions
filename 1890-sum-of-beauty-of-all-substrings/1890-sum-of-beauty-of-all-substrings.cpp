class Solution {
public:
    int beautySum(string s) {
        int n = s.size(), ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                vector<int> freq(26, 0);

                int mini = INT_MAX, maxi = 0;

                for(int k = i; k <= j; k++) {
                    freq[s[k] - 'a']++;
                }

                for(int k = 0; k < 26; k++) {
                    if(freq[k] == 0) continue;
                    if(freq[k] > maxi) maxi = freq[k];
                    if(freq[k] < mini) mini = freq[k];
                }
                
                ans += (maxi - mini);

            }
        }
        return ans;
    }
};