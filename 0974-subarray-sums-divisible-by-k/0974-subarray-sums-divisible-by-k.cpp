class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int , int>mp;
        mp[0] = 1;
        int count =0;
        int prefix_sum=0;
        for(int i=0 ; i<n ; i++){
            prefix_sum += nums[i];
            int rem = prefix_sum % k;
            if(rem <0)rem += k;
            if(mp.find(rem) != mp.end()){
                count += mp[rem];
            }
            mp[rem]++;
        }
        return count;
    }
};