class Solution {
public:
    bool canMake(vector<int>& bloomDay, int days, int m, int k, int n) {
        int st = 0, end = 0, ans = 0, cnt = 0;

        while(end < n) {
            if(bloomDay[end] <= days) cnt++;
            while(end + 1 < n && end - st < k - 1) {end++; if(bloomDay[end] <= days) cnt++;}

            while(end < n && cnt < k) {
                if(bloomDay[st] <= days) cnt--;
                st++;
                
                end++;
                if(end < n && bloomDay[end] <= days) cnt++;
            }
            if(cnt == k) ans++;
            st = end + 1;
            end = st;
            cnt = 0;
        }

        if(ans >= m) return true;
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