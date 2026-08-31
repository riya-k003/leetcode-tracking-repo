class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l =0;
        double sum =0;
        double maxi = INT_MIN;
        for(int r=0 ; r<nums.size() ; r++){
            sum += nums[r];
            if(r-l+1 == k){
                maxi = max(sum/k , maxi);
                sum-=nums[l];
                l++;
            }
        }
        return maxi;
    }
};