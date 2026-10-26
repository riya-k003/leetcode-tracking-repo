class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int prifix =1;
        int suffix =1;
        
        for(int i =0 ; i<n ; i++){
            if(prifix == 0)prifix = 1;
            if(suffix == 0)suffix = 1;
            prifix *= nums[i];
            suffix *= nums[n-i-1];
            maxi = max(maxi , max(prifix , suffix));
        }
        return maxi;
    }
};