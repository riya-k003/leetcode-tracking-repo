class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int k = tasks.size();
        unordered_map<char , int> mp;
        priority_queue<pair<int , char>>pq;
        int countMaxFreq = 0;
        for (auto ch : tasks) {
            mp[ch]++;
        }
        for(auto ch : mp){
            pq.push({ch.second, ch.first});
        }
        int maxfreq = pq.top().first;
        while(!pq.empty()){
            if(pq.top().first == maxfreq){
        countMaxFreq++;
            }
        pq.pop();
        }
        // for (auto ch : mp) {
        //     maxfreq = max(ch.second, maxfreq);
        // }
        
        // for (auto p : mp) {
        //     if (p.second == maxfreq) {
        //         countMaxFreq++;
        //     }
        // }

        int p = ((maxfreq - 1) * (n + 1) + countMaxFreq);
        int ans = max(p, k);
        return ans;
    }
};