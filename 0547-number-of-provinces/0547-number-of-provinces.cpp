class Solution {
public:
void dfs(int v , unordered_map<int , vector<int>>adj , unordered_map<int , bool>&visited){
    visited[v] = 1;
    for(auto &u : adj[v]){
        if(!visited[u]){
            dfs(u , adj , visited);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int , vector<int>>adj;
        unordered_map<int  , bool>visited;
        int count =0;
        int n = isConnected.size();
        for(int i =0 ; i<n ; i++){
           for( int j =0 ; j<n ; j++){
            if(isConnected[i][j] == 1){
                adj[i].push_back(j);
            }
           }
        }
        for(int i =0; i<adj.size() ; i++){
            if(!visited[i]){
        dfs(i , adj , visited);
        count++;
            }
        }

        return count;

    }
};