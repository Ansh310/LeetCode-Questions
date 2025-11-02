class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for(int i = 0; i < walls.size(); i++) {
            grid[walls[i][0]][walls[i][1]] = 2;
        }

        for(int i = 0; i < guards.size(); i++) {
            grid[guards[i][0]][guards[i][1]] = 3;
        }

        for(int i = 0; i < guards.size(); i++) {
            

            int r = guards[i][0], c = guards[i][1];

            for(int i = r + 1; i < m; i++) {
                if(grid[i][c] == 2 || grid[i][c] == 3) break;
                grid[i][c] = 1;
            }

            for(int i = r - 1; i >= 0; i--) {
                if(grid[i][c] == 2 || grid[i][c] == 3) break;
                grid[i][c] = 1;
            }

            for(int j = c + 1; j < n; j++) {
                if(grid[r][j] == 2 || grid[r][j] == 3) break;
                grid[r][j] = 1;
            }

            for(int j = c - 1; j >= 0; j--) {
                if(grid[r][j] == 2 || grid[r][j] == 3) break;
                grid[r][j] = 1;
            }
            
        }

        int cnt = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) cnt++;
            }
        }

        return cnt;
    }
};