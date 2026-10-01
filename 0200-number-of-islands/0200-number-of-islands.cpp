class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int , int>>q;
        int count =0;
        for(int i =0 ; i<m ; i++){
            for(int j =0 ; j<n ; j++){
                if(grid[i][j] == '1'){
                    q.push({i , j});
                    grid[i][j] = '#';
                    while(!q.empty()){
                        pair<int , int>cord = q.front();
                        q.pop();
                        int k = cord.first;
                        int l = cord.second;
                        if(k+1 < m && grid[k+1][l] == '1'){
                            q.push({k+1 , l});
                            grid[k+1][l] = '#';
                        }
                        if(k-1 >= 0 && grid[k-1][l] == '1'){
                             q.push({k-1 , l});
                            grid[k-1][l] = '#';
                        }
                        if(l+1 < n && grid[k][l+1] == '1'){
                             q.push({k , l+1});
                            grid[k][l+1] = '#';
                        }
                        if(l-1 >=0 && grid[k][l-1] == '1'){
                             q.push({k , l-1});
                            grid[k][l-1] = '#';
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }
};