class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int m = s.size();
        int n = p.size();

        if(m<n)return ans;
        vector<int>p_count(26,0) ,window(26,0);


        for(int i =0 ; i<n ; i++){
            p_count[p[i]-'a']++;
        }
        

        for(int i=0 ; i<m ; i++){
            window[s[i]-'a']++;

            if(i>=n){
                window[s[i-n] - 'a']--;
            }

            if(window == p_count){
                ans.push_back(i-n+1);
            }
        }
        return ans;
    }
};