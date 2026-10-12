class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>sets(n , -1);
        queue<int>q;
        for(int i =0 ; i<n ; i++){
            if(sets[i] == -1){
                sets[i] = 0;
                
                q.push(i);
                while(!q.empty()){
                   int node = q.front();
                   int sign = sets[node];
                   q.pop();
                   for(int j =0 ; j<graph[node].size() ; j++){
                    if(sets[graph[node][j]] == -1 && sign == 0){
                        sets[graph[node][j]] = 1;
                        q.push(graph[node][j]);
                    }
                    else if(sets[graph[node][j]] == -1 && sign == 1){
                        sets[graph[node][j]] = 0;
                        q.push(graph[node][j]);
                    }
                   else if(sets[graph[node][j]] != -1){
                        if(sign == 1 && sets[graph[node][j]] == 1)return false;
                        if(sign == 0 && sets[graph[node][j]] == 0)return false;
                    }
                   }
                }
            }
        }
            
        return true;
    }
};