class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int , int>mp;
        int maxi=0;
        int s =0;
        for(int r =0 ; r<n ; r++){
            mp[fruits[r]]++;
            while(mp.size() > 2){
                mp[fruits[s]]--;
                if(mp[fruits[s]] == 0){
                    mp.erase(fruits[s]);
                }
                s++;
            }
            maxi = max(maxi , r-s+1);
        }
          return maxi; 
    }
};