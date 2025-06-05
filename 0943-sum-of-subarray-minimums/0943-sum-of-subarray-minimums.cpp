class Solution {
public:
    int* prevSmaller(vector<int>& arr, int n) {
        stack<int> s;
        int* pse = new int[n];

        for(int i = 0; i < n; i++) {
            while(!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }

            pse[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return pse;
    }

    int* nextSmaller(vector<int>& arr, int n) {
        stack<int> s;
        int* nse = new int[n];

        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }

            nse[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        return nse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = (int)1e9 + 7;
        long long int sum = 0;

        int* nse = nextSmaller(arr, n);
        int* pse = prevSmaller(arr, n);

        for(int i = 0; i < n; i++) {
            long long int rightRange = nse[i] - i;
            long long int leftRange = i - pse[i];
            sum = (sum + ((rightRange * leftRange) % mod * arr[i]) % mod) % mod;
        }
        return sum;
    }
};