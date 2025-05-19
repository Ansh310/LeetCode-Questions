class Solution {
public:
    bool canMake(vector<int>& bloomDay, int days, int m, int k, int n) {
        int numOfBouquets = 0, cnt = 0;
        
        for(int i = 0; i < n; i++) {
            if(bloomDay[i] <= days) cnt++;

            else cnt = 0;

            if(cnt == k) {numOfBouquets++; cnt = 0;}
        }
        if(numOfBouquets >= m) return true;
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        int maxi = 0;
        for(int i = 0; i < n; i++) maxi = max(maxi, bloomDay[i]);

        int s = 0, e = maxi, minDays = -1;

        while(s <= e) {
            int mid = s + (e - s) / 2;

            if(canMake(bloomDay, mid, m, k, n)) {e = mid - 1; minDays = mid;}

            else s = mid + 1;
        }

        return minDays;
    }
};