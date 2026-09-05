class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        int mini = INT_MAX;
        int l =0 , r=0;
        while(r<n){
            sum+=nums[r];
            if(sum > target){
                while(sum > target){
                mini = min(r-l+1 , mini);
                    sum -= nums[l];
                    l++;
            }

            }
             if(sum == target){
                mini = min(r-l+1 , mini);
            }
            r++;
        }
      return (mini == INT_MAX) ?  0 : mini;   
    }
};