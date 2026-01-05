class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;
        int min_element = INT_MAX, count = 0;
        bool zero_present = false;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) zero_present = true;
                else if(matrix[i][j] < 0) {

                    count++;
                    sum += -matrix[i][j];

                }
                else {
                    sum += matrix[i][j];
                }
                int temp = abs(matrix[i][j]);
                min_element = min(min_element, temp);
            }
        }

        return (count % 2 == 0 || zero_present) ? sum : sum - 2 * min_element;
    }
};