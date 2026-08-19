class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int cnt1 = 1, cnt2 = 1, cnt3 = 1, ans = n * 2;
        unordered_map<int, unordered_set<int>> mp;

        for(int i = 0; i < reservedSeats.size(); i++) {
            int idx1 = reservedSeats[i][0];

            int idx2 = reservedSeats[i][1];


            if(idx2 >= 2 && idx2 <= 5) mp[idx1].insert(0);
            if(idx2 >= 4 && idx2 <= 7) mp[idx1].insert(1);
            if(idx2 >= 6 && idx2 <= 9) mp[idx1].insert(2);
        }

        for(auto key: mp) {
            if(key.second.size() < 3 && key.second.size() > 0) ans -= 1;
            else if(key.second.size() == 3) ans -= 2;
        }

        return ans;
    }
};