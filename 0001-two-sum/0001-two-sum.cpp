class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int>mp;
        int sum =0;
        for(int i =0 ; i<n ; i++){
            if(mp.find(target-nums[i])!= mp.end()){
               int first = mp[target-nums[i]];
               int second = i;
                return {first , second};
            }
            mp[nums[i]] = i;
            }
        return {};
    }
};