class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i =0 ; i<n ; i++){
            if(nums[i]%2 == 0){
                nums[i] = 0;
            }
            else{
                nums[i] = 1;
            }
        }
        unordered_map<int , int>freq;
        int count =0;
        freq[0] =1;
        int prefix_sum =0;
        for(int i =0 ; i<n ; i++){
            prefix_sum += nums[i];
            if(freq.find(prefix_sum-k) != freq.end()){
                count += freq[prefix_sum-k];
            }
            freq[prefix_sum]++;
        }
        return count;
    }
};