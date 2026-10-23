class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int s =0;
        int ans = INT_MAX;
        int sum =0;
        for(int r =0 ; r<n ; r++){
            sum += nums[r];
            while(s<=r && sum >= target ){
                ans = min(ans , r-s+1);
                sum-=nums[s];
                s++;
            }
        }
        if(ans == INT_MAX)return 0;
        return ans;
    }
};