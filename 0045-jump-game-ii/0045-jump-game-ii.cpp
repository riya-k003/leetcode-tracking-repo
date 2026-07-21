class Solution {
public:
    int jump(vector<int>& nums) {
        int max_pos=0;
        int cnt =0;
        int curr =0;
        int n = nums.size();
        if(n==1)return 0;
        for(int i =0 ; i<n-1 ; i++){
            max_pos = max(nums[i]+i , max_pos);
            if(i == curr){
                cnt++;
                curr = max_pos;
            }
        }
        return cnt;
    }
};