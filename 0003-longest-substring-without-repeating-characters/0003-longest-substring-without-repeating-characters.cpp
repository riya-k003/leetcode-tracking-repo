class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l =0  ,  r = 0;
        vector<int>ch(256 , -1);
        int maxi = 0;

        while(r<n){
           if(ch[s[r]] != -1){
           if(ch[s[r]] >= l){
             l = ch[s[r]]+1;
           }
           }
           maxi = max(maxi , r-l+1);
           ch[s[r]] = r;
            r++;
        }
        return maxi;
    }
};