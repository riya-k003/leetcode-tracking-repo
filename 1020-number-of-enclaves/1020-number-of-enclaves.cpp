class Solution {
public:
    vector<pair<int, int>> ordi{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i - 1 < 0 || i + 1 == m || j - 1 < 0 || j + 1 == n) &&
                    grid[i][j] == 1) {
                    grid[i][j] = -1;
                    q.push({i, j});
                    while (!q.empty()) {
                        pair<int, int> cord = q.front();
                        q.pop();

                        for (auto& k : ordi) {
                            int new_i = cord.first + k.first;
                            int new_j = cord.second + k.second;
                            if (new_i < m && new_i >= 0 && new_j < n &&
                                new_j >= 0 && grid[new_i][new_j] == 1) {
                                grid[new_i][new_j] = -1;
                                q.push({new_i , new_j});
                            } 
                        }
                    }
                }
               
            }
        }
        for(int i =0 ; i<m ; i++){
            for(int j =0 ; j<n ; j++){
                if(grid[i][j] == 1)count++;
            }
        }
        return count;
    }
};