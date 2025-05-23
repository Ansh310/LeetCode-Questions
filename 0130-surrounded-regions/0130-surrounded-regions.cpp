class Solution {
public:
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};

    void dfs(vector<vector<char>>& board, int i, int j, int m, int n) {
        board[i][j] = 'C';

        for(int r = 0; r < 4; r++) {
                int row = i + dr[r];
                int col = j + dc[r];

                if(row >= 0 && row < m && col >= 0 && col < n && board[row][col] == 'O') {
                    dfs(board, row, col, m, n);
                }
            
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        for(int j = 0; j < n; j++) {if(board[0][j] == 'O') dfs(board, 0, j, m, n); if(board[m - 1][j] == 'O')    dfs(board, m - 1, j, m, n);}

        for(int i = 0; i < m; i++) {if(board[i][0] == 'O') dfs(board, i, 0, m, n); if(board[i][n - 1] == 'O') dfs (board, i, n - 1, m, n);}
        

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';

                else if(board[i][j] == 'C') board[i][j] = 'O';
            }
        }
    }
};