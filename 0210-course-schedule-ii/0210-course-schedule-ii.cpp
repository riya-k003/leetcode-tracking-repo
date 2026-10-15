class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>adj(n);
        vector<int>ingre(n,0);
        vector<int>ans;
        for(const auto& edj : prerequisites ){
            int i = edj[0];
            int j = edj[1];
            adj[j].push_back(i);
            ingre[i]++;
        }
        queue<int>q;
        for(int i=0 ; i<n ; i++){
            if(ingre[i] == 0){
                q.push(i);
            }
        }
        int cnt =0;

        while(!q.empty()){
            int course = q.front();
            q.pop();
            for(auto& ass : adj[course]){
                ingre[ass]--;
                if(ingre[ass] == 0){
                    q.push(ass);

                }
            }
            cnt++;
            ans.push_back(course);
        }
       if(cnt < n){
        while(!ans.empty()){
            ans.pop_back();
        }
       }
        return ans;
    }
};