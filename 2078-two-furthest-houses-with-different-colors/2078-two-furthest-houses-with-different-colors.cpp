class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size(), max_dist = 0;

        for(int i = n - 1; i >= 1; i--) {
            if(colors[i] != colors[0]) {max_dist = i; break;}
        }

        for(int j = 0; j < n - 1; j++) {
            if(colors[j] != colors[n - 1]) {
                max_dist = max(max_dist, n - 1 - j);
                break;
            }
        }

        return max_dist;
    }
};