class Solution {
public:
  unordered_map<char , int>mp;
     unordered_map<char , int>mp2;
bool check(string s2 , int l , int r){
    for(int i =l ; i<=r; i++){
        if(mp.find(s2[i]) == mp.end()) return false;
        else {
            if(mp[s2[i]] != mp2[s2[i]])return false;
        }
    }
    return true;
}
    bool checkInclusion(string s1, string s2) {

        for(auto& ch:s1){
            mp[ch]++;
        }
        int n = s1.size();
        int l =0;
    for(int r=0 ; r<s2.size() ; r++){
        mp2[s2[r]]++;
        if(r-l+1 == n){
          if(check(s2 , l , r))return true;
          mp2[s2[l]]--;
          l++;
          if(mp2[s2[r]] == 0){
            mp2.erase(s2[l]);
          }
        }
    }
    return false;
    }
};