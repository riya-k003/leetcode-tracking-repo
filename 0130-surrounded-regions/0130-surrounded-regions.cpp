class Solution {
public:
    vector<pair<int, int>> ordi{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> q;
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                q.push({0, j});
            }
            if (board[m-1][j] == 'O') {
                q.push({m-1, j});
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
            }
            if (board[i][n-1] == 'O') {
                q.push({i, n-1});
            }
        }
        while (!q.empty()) {
            pair<int, int> cord = q.front();
            q.pop();
            int x = cord.first;
            int y = cord.second;
            board[x][y] = '#';
            for (auto& idx : ordi) {
                int new_i = x + idx.first;
                int new_j = y + idx.second;
                if (new_i < m && new_i >= 0 && new_j < n && new_j >=0 && board[new_i][new_j] == 'O') {
                    board[new_i][new_j] = '#';
                    q.push({new_i , new_j});
                };
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};