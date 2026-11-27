class Solution {
public:
unordered_map<char , int>mp;
bool valid(int st , int e , int k){
    int max_freq =0;
    for(auto & el : mp){
        max_freq = max(el.second , max_freq);
    }
    if(e-st+1 - max_freq <= k)return true;
     return false;
}
    int characterReplacement(string s, int k) {
        int n= s.size();
        int maxi =0;
       int st =0;
       for(int e =0 ; e<n ; e++){
        mp[s[e]]++;
        if(valid(st , e , k)){
            maxi = max(e-st+1 , maxi);
        }
        else{
            while(!valid(st , e , k)){
                mp[s[st]]--;
                st++;
            }
        }
       
       }
        return maxi;
    }
};