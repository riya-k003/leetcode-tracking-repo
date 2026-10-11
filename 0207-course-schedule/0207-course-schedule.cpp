class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        int m = prerequisites.size();
        int cnt =0;
        map<int , int>count;
        for(int i=0 ; i<n ; i++){
            count[i] = 0;
        }
    
        map<int , vector<int>>mp;
        for(int i=0 ; i<m ; i++){
                mp[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        queue<int>q;
        for(auto& vec: mp){
            count[vec.first] = vec.second.size();
        }
        for(auto& s: count){
             if(s.second == 0){
                q.push(s.first);
               cnt++;
            }
        }
        
        while(!q.empty()){
            int course = q.front();
            q.pop();
            if(cnt == numCourses)return true;
            for(auto& i : mp){
                for(int j =0 ; j<i.second.size() ; j++){
                    if(i.second[j] == course){
                    count[i.first]--;
                    if(count[i.first] == 0){
                        q.push(i.first);
                        cnt++;
                    }
                }
                }
                
            }
        }

return false;
        
    }
};