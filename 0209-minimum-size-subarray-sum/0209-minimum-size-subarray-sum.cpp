class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int s =0;
        int mini = INT_MAX;
        int sum=0;
        for(int e =0 ; e<n ; e++){
            sum += nums[e];
            if(sum >= target){
                mini = min(e-s+1 , mini);
                while(sum >= target){
                     mini = min(e-s+1 , mini);
                    sum -= nums[s];
                    s++;
                }
            }
        }
        return (mini == INT_MAX) ? 0 : mini;
    }
};