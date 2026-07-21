class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_pos = 0;
        int n = nums.size();
        if(n<2)return true;
        for(int i =0 ; i<n-1 ; i++){
            max_pos = max(nums[i]+i , max_pos);
            if(max_pos >= n-1)return true;
            if(max_pos == i)return false;
        }
        return false;
    }
};