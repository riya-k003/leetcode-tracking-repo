class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int maxi =0;
        unordered_map<int , int>mp;
        mp[0] = -1;
        int sum =0;
        for(int i =0 ; i<n ; i++){
            if(nums[i] == 0){
                sum--;
            }
            else{
                sum++;
            }
            if(mp.find(sum) != mp.end()){
                maxi = max(i-mp[sum] , maxi);
            }
            else{
            mp[sum] = i;
            }
        }
        return maxi;
    }
};