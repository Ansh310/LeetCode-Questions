class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        string ans = "";

        for(int i = 0; i < n; i++) {
            string word = words[i];

            int sum = 0;

            for(int i = 0; i < word.size(); i++) sum += weights[word[i] - 'a'];

            sum = sum % 26;

            ans += (char)('z' - sum);
        }

        return ans;
    }
};