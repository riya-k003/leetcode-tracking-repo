class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>adj(n);
        vector<int>count(n , 0);
        for(const auto& edj : prerequisites){
            int i = edj[0];
            int j = edj[1];
            adj[j].push_back(i);
            count[i]++;
        }
        queue<int>q;
        for(int i =0 ; i<n ; i++){
            if(count[i] == 0){
                q.push(i);
            }
        }
        int cntcourse =0;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            for(auto& ass : adj[course]){
                count[ass]--;
                if(count[ass] == 0){
                    q.push(ass);
                }
            }
            cntcourse++;

        }
        return (cntcourse == n);
        
    }
};