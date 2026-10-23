class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int , int>mp;
        int maxi=0;
        int s =0;
        for(int r =0 ; r<n ; r++){
            if(mp.size() < 2 && mp.find(fruits[r]) == mp.end()){
                mp[fruits[r]]++;
            }
            else if(mp.find(fruits[r]) != mp.end()){
                mp[fruits[r]]++;
            }
            else{
                int total =0;
                for(auto& el: mp){
                total += el.second;
                }
                maxi = max(maxi , total);
                while(mp.size() == 2){
                    mp[fruits[s]]--;
                    if(mp[fruits[s]] == 0){
                        mp.erase(fruits[s]);
                    }
                    s++;
                }
                mp[fruits[r]]++;
            }

        }
        int total = 0;
        if(mp.size() == 2 || maxi ==0 ){
        for(auto& el : mp){
            total += el.second;
        }
        maxi = max(maxi  , total);
        }
        return maxi;
    }
};