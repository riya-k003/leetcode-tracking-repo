class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int maxi =0;
        unordered_map<int , int>mp;
        for(int r =0 ; r<fruits.size() ; r++){
            mp[fruits[r]]++;
            while(mp.size() > 2){
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            maxi = max(r-l+1 ,maxi);
        }
        return maxi;
    }
};