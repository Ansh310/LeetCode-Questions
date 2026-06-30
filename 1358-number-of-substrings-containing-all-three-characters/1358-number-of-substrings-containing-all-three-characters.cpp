class Solution {
public:
    bool check(vector<int>& f) {
        if(f[0] && f[1] && f[2]) return true;
        return false;
    }

    int numberOfSubstrings(string s) {
        int count = 0;
        vector<int> f(3, 0);
        int n = s.size();
        int i = 0, j = 0;

        while(j < n) {

            while(j < n && !check(f)) {f[s[j] - 'a']++; j++;}

            if(j < n) {
                j--;
                count += n - j;
                f[s[j] - 'a']--;

                f[s[i] - 'a']--;
            

                i++;
            }

            
        }

        while(check(f)) {
            count++;
            f[s[i] - 'a']--;
            i++;

        }

        
        return count;
    }
};