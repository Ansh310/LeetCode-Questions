class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!mat[i][j]) {q.push({i, j});}
            }
        }
        int level = 1;
        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                auto front = q.front();
                q.pop();

                int i = front.first, j = front.second;

                if(i + 1 < m && mat[i + 1][j] == 1) {q.push({i + 1, j}); mat[i + 1][j] = -level;}
                
                if(i - 1 >= 0 && mat[i - 1][j] == 1) {q.push({i - 1, j}); mat[i - 1][j] = -level;}
    
                if(j + 1 < n && mat[i][j + 1] == 1) {q.push({i, j + 1}); mat[i][j + 1] = -level;}
            
                if(j - 1 >= 0 && mat[i][j - 1] == 1) {q.push({i, j - 1}); mat[i][j - 1] = -level;}


            }
            level++;
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                mat[i][j] = -mat[i][j];
            }
        }

        return mat;
    }
};