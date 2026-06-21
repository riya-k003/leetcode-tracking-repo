class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int>mp;
        int n = nums.size();
        vector<int>ans;
        for(int i =0 ; i<n ; i++){
            int y = target - nums[i];
            if(mp.find(y) != mp.end()){
                ans.push_back(mp[y]);
                ans.push_back(i);
                break;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};