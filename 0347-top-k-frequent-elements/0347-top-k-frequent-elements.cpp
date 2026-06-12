class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int ,int>mp;
        for(auto & el: nums){
            mp[el]++;
        }
        priority_queue<pair<int, int>>max_heap;
        for(auto & pair : mp){
            max_heap.push({pair.second , pair.first});
        }
        vector<int>ans;
        while(k>0){
            ans.push_back(max_heap.top().second);
            max_heap.pop();
            k--;
        }
        return ans;
    }
};