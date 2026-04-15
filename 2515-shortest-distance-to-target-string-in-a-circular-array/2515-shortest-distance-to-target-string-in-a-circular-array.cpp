class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int i = startIndex, j = startIndex, n = words.size(), flag = 1;

        while(i != j || flag) {
            if(words[i] == target) {
                if(i < startIndex) return n - startIndex + i;
                return i - startIndex;

            }

            else if(words[j] == target) {
                if(j < startIndex) return startIndex - j;
                return startIndex + (n - j);
                
            }
            i = (i + 1) % n;
            j = (j - 1 + n) % n;
            flag = false;
        }
        return words[i] == target ? i - startIndex : -1;
    }
};