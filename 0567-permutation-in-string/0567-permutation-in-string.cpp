class Solution {
public:

    bool check(int l , int r , string s2 , unordered_map<int , int>&freq1 , unordered_map<int , int>& freq2){
        for(int i = l ; i<=r ; i++){
            if(freq1.find(s2[i]) == freq1.end())return false;
            if(freq1[s2[i]] != freq2[s2[i]])return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        unordered_map<int , int>freqs1;
        for(auto & ch: s1){
            freqs1[ch]++;
        }
        int l =0, r=0;
        int n = s2.size();
        unordered_map<int , int>freqs2;
        for(int r =0 ; r<n ; r++){
            freqs2[s2[r]]++;
            if(r-l+1 == s1.size()){
                if(check(l , r , s2, freqs1 , freqs2)) return true;
                else{
                freqs2[s2[l]]--;
                if(freqs2[s2[l]] == 0){
                    freqs2.erase(s2[l]);
                }
                l++;
                }
            }
        }
        return false;
    }
};