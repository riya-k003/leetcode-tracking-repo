class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string , vector<string>>mp;
        for(int i =0 ; i<n ; i++){
            string st = strs[i];
            sort(st.begin() , st.end());
            mp[st].push_back(strs[i]);
        }

        vector<vector<string>>ans;
        for(auto& vec : mp){
            ans.push_back(vec.second);
        }
        
        return ans;
    }
};