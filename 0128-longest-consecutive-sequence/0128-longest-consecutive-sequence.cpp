class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin() , nums.end());
        int n = nums.size();
        int maxi =0;

        for(auto& el : st){
            int count = 1;
            if(st.find(el-1) != st.end())continue;
            int curr = el;
            while(st.count(curr+1)){
                count++;
                curr++;
            }
        maxi = max(maxi , count);
        }
        return maxi;
    }
};