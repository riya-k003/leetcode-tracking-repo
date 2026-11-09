class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin() , nums.end());
        int n = nums.size();
        int maxi =0;

        for(auto& el : st){
            int count = 1;
        for(int i=1 ; i<n ; i++){
            if(st.find(el+i) != st.end()){
                count++;
            }
            else {
                break;
            }
        }
        maxi = max(maxi , count);
        }
        return maxi;
    }
};