class Solution {
public:
vector<pair<int , int>>ordi{{-1,0} , {1,0} , {0,-1} , {0,1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
set<pair<int , int>>visited;
    queue<pair<pair<int , int> , int>>q;
    for(int i=0 ; i<m ; i++){
        for(int j =0; j<n ; j++){
            int  count =0;
            if(mat[i][j] == 0){
                int k =i;
                int l =j;
                count++;
               for(auto &idx : ordi){
                int new_i = k+idx.first;
                int new_j = l+idx.second;

                if(new_i < m && new_i >= 0 && new_j < n && new_j >= 0 && mat[new_i][new_j] == 1 && !visited.count({new_i , new_j})){
                     q.push({{new_i , new_j} , count});
                visited.insert({new_i , new_j});
                }
               }
            }
        }
    }

    while(!q.empty()){
        pair<pair<int , int> , int>cord = q.front();
        q.pop();
        int i = cord.first.first;
        int j = cord.first.second;
        int cnt = cord.second;
        mat[i][j] = cnt;
        for(auto &idx : ordi){
            int new_i = i+idx.first;
            int new_j = j+idx.second;
            int count = cnt;
            if(new_i < m && new_i >=0 && new_j <n && new_j >= 0 && mat[new_i][new_j] == 1 && !visited.count({new_i , new_j})){
                q.push({{new_i , new_j} , ++count});
                visited.insert({new_i , new_j});
            }
        }
    }
    return mat;   
    }
};