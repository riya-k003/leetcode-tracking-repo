class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int i =0;
        int maxi = 0;
        for(int r =0 ; r<s.size() ; r++){
            while(i<s.size() && st.find(s[r]) != st.end()){
                st.erase(s[i]);
                i++;
            }
    
            st.insert(s[r]);
            maxi = max(r-i+1 ,maxi);
        }
        return maxi;
    }
};