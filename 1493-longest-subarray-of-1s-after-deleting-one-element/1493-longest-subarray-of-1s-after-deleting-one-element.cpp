class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int s =0; 
        int r=0 ;
       int i =-1;
        
        while(r<n){
            if(s<=r && nums[r] == 0 && i != -1){
                maxi = max(r-s-1 , maxi);
                s = i+1;
                i = r;
            }
            else if(s<=r && nums[r] == 0 && i == -1){
                i = r;
            }
            maxi = max(r-s , maxi);
            r++;
        }
        return maxi;
    }
};