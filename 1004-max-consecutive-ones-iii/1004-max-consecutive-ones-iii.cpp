class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int t =0;
        int s =0;
        int maxi =0;
        for(int e=0 ; e<n ; e++){
            if(nums[e] == 0)t++;
                while(t>k){
                    if(nums[s] == 0)t--;
                    s++;
                }
                maxi = max(e-s+1 , maxi);
        }
        return maxi;
    }
};