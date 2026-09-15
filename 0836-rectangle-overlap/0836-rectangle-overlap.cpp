class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int min_X = min(rec1[0], rec2[0]);
        int min_Y = min(rec1[1], rec2[1]);

        if(min_X == rec1[0] && min_Y == rec1[1]) {
            if(rec1[2] > rec2[0] && rec1[3] > rec2[1]) return true;
        }
        else if(min_X == rec1[0] && min_Y == rec2[1]) {
            if(rec1[2] > rec2[0] && rec2[3] > rec1[1]) return true;
        }
        else if(min_X == rec2[0] && min_Y == rec1[1]) {
            if(rec1[0] < rec2[2] && rec1[3] > rec2[1]) return true;
        }
        else {
            if(rec2[2] > rec1[0] && rec2[3] > rec1[1]) return true;
        }

        return false;
    }
};