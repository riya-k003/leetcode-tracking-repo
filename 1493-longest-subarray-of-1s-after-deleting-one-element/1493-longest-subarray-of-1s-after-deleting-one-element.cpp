class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int s =0; 
        int r=0 ;
       int i =-1;
        
        while(r<n){
            if(nums[r] == 0 && i != -1){
                s = i+1;
                i = r;
            }
            else if(nums[r] == 0 && i == -1){
                i = r;
            }
            maxi = max(r-s , maxi);
            r++;
        }
        return maxi;
    }
};