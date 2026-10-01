class Solution {
public:

    void dfs(int i , int j , vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        if(grid[i][j] == '0' || grid[i][j] == '#')return;
        if(grid[i][j] == '1'){
            grid[i][j] = '#';
        }
        if(i+1 < m)dfs(i+1 , j , grid);
        if(i-1 >=0)dfs(i-1 , j , grid);
        if(j+1 < n)dfs(i , j+1 , grid);
        if(j-1 >=0)dfs(i , j-1 , grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int , int>>q;
        int count =0;
        for(int i =0 ; i<m ; i++){
            for(int j =0 ; j<n ; j++){
                if(grid[i][j] == '1'){
                    dfs(i , j , grid);
                    count++; 
            }
            }
        }
        return count;
    }
};