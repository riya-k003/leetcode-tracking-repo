class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int , long long>mp;
        long long curr = 0;
        for(int i=0 ; i<tasks.size() ; i++){
            if(mp.find(tasks[i]) != mp.end()){
                
                    long long last = mp[tasks[i]];
                    long long next_pos = max(last+space+1 , curr);
                    curr = next_pos+1;
                    mp[tasks[i]] = next_pos;
                }
            else{
                mp[tasks[i]] = curr;
            curr++;
            }
        }
        return curr;
    }
};