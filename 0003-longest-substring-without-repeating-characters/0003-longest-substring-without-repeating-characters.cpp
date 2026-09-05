class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256 , -1);
        int l =0 , r= 0;
        int maxi = 0;
        while(r<s.size()){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >=l){
                    l = hash[s[r]]+1;
                }
            }
            maxi = max(r-l+1 , maxi);
            hash[s[r]] = r;
            r++;
        }
        return maxi;
    }
};