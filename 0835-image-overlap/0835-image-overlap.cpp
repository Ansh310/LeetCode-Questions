class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> onesInImg1;
        vector<pair<int, int>> onesInImg2;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(img1[i][j] == 1) onesInImg1.push_back({i, j});
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(img2[i][j] == 1) onesInImg2.push_back({i, j});
            }
        }

        unordered_map<int, int> map;
        int num_ones_1 = onesInImg1.size();
        int num_ones_2 = onesInImg2.size();
        int max_overlap = 0;

        for(int i = 0; i < num_ones_1; i++) {
            for(int j = 0; j < num_ones_2; j++) {
                int x1 = onesInImg1[i].first;
                int y1 = onesInImg1[i].second;
                int x2 = onesInImg2[j].first;
                int y2 = onesInImg2[j].second;

                int key = (x2 - x1 + n) * (2 * n + 1) + (y2 - y1 + n);
                map[key]++;
                max_overlap = max(max_overlap, map[key]);
            }
        }

        return max_overlap;
    }
};