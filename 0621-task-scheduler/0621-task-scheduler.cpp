class Solution {
public:

struct Node{
    int next;
    int left;
    char task;
};
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>>freq;
        queue<Node>cooldown;
        int t =0;
        unordered_map<char , int>mp;
        for(auto & ch : tasks){
            mp[ch]++;
        }
        for(auto & m: mp){
            freq.push({m.second , m.first});
        }
        while(!cooldown.empty() || !freq.empty()){
             while(!cooldown.empty() && cooldown.front().next == t){
                    freq.push({cooldown.front().left , cooldown.front().task });
                    cooldown.pop();
                }
                
        if(!freq.empty()){
                char c = freq.top().second;
                int f = freq.top().first - 1;
                freq.pop();
                if(f!=0){
                    int next = t+n+1;
                    cooldown.push({next ,f , c});
                }
                t++;
            }
          else{
                t = cooldown.front().next;
                }
        }
        return t;
    }
};