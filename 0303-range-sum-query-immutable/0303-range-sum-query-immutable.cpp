class NumArray {
public:
    vector<int>prefix_sum;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix_sum.resize(n+1 , 0);
        int sum =0;
        prefix_sum[0] = 0;
        for(int i =0 ; i<n ; i++){
            sum += nums[i];
            prefix_sum[i+1] = sum;
        }
        
    }
    
    int sumRange(int left, int right) {
    return prefix_sum[right+1] - prefix_sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */