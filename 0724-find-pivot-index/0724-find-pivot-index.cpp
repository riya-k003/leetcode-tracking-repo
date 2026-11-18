class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix_sum(n+1 , 0);
        vector<int>suffix_sum(n+1 , 0);
        int sum =0;

        for(int i =0 ; i<n ; i++){
            sum += nums[i];
            prefix_sum[i+1] = sum;
        }

        sum=0;
        for(int i=n-1 ; i>=0 ; i--){
            sum += nums[i];
            suffix_sum[i] = sum;
        }

        for(int i=0 ; i<n ; i++){
            if(prefix_sum[i] == suffix_sum[i+1])return i;
        }
        return -1;
        
    }
};