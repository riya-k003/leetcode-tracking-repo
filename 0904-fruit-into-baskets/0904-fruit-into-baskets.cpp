class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int , int>mp;
        if(n<2)return 1;
        if (n==2)return 2;
        int l =0 , r =0;
        int maxi =0;
        int lastTypeStart =0;
        while(r<n){
            if(mp.size() == 2 && mp.find(fruits[r]) == mp.end()){
                int cnt =0;
                for(auto el : mp){
                    cnt += el.second;
                }
                maxi = max(cnt , maxi);
                while(l<lastTypeStart){
                    mp[fruits[l]]--;
                    if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
                    l++;
                }
                mp[fruits[r]]++;
            }else if(mp.size() <=2 && mp.find(fruits[r]) != mp.end()){
                mp[fruits[r]]++;
                     int cnt =0;
                for(auto el : mp){
                    cnt += el.second;
                }
                maxi = max(cnt , maxi);
            }
            else{
            mp[fruits[r]]++;
            }
            if(r-1>= 0 && fruits[r-1] != fruits[r]){
                lastTypeStart = r;
            }
            r++;
        }
        return maxi;
    }
};