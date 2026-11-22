class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)return n-1;
        for(int i =0 ; i<n ; i++){
            if(i+1<n && nums[i] > nums[i+1])return i;
        }
        return n-1;
    }
};