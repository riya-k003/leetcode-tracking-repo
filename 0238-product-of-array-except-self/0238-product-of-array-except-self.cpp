class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>before(n , 1);
        vector<int>after(n , 1);

        for(int i =1 ; i<n ; i++){
           before[i] = before[i-1]*nums[i-1];
        }

        for(int i = n-2 ; i>=0 ; i--){
           after[i] = after[i+1]*nums[i+1];
        }  
        vector<int>ans(n);
        for(int i =0 ; i<n ; i++){
            ans[i] = (before[i]*after[i]);
        } 
        return ans;   
    }
};