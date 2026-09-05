class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char , int>st;
        int i =0;
        int maxi = 0;
        for(int r =0 ; r<s.size() ; r++){
            while(i<s.size() && st.find(s[r]) != st.end()){
                st[s[i]]--;
                if(st[s[i]] == 0){
                    st.erase(s[i]);
                }
                i++;
            }
                    st[s[r]]++;
                maxi = max(r-i+1 ,maxi);
        }
        return maxi;
    }
};