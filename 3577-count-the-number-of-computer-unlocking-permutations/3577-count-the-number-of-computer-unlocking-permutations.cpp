class Solution {
public:
    long long fact(long long n) {
    const long long MOD = 1000000007;
    if (n == 0 || n == 1) return 1;

    long long result = 1;
    for (long long i = 2; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}


    int countPermutations(vector<int>& complexity) {
        bool start_unique_minimum = true;
        int label_0 = complexity[0], n = complexity.size();

        for(int i = 1; i < n; i++) {
            if(complexity[i] <= label_0) start_unique_minimum = false;
        }
    
        return start_unique_minimum ? fact(n - 1) : 0;
    }
};