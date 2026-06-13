class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int st =0;
        int maxi =0;
        unordered_map<int , int>mp;
        for(int e =0 ; e<s.size(); e++){
            if(mp.find(s[e]) != mp.end()){
                while(st<=e && (mp.find(s[e]) != mp.end())){
                    mp[s[st]]--;
                    if(mp[s[st]] == 0){
                        mp.erase(s[st]);
                    }
                    st++;
                }
            }
            maxi = max(e-st+1 , maxi);
                mp[s[e]]++;
            }
        return maxi;
    }
};