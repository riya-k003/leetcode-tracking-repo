class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int sum =0;
        unordered_map<int , int>mp;
        int first =0;
        int second =0;
        for(int i =0 ; i<n ; i++){
           
           if(mp.find(target-numbers[i]) != mp.end()){
            first = mp[target-numbers[i]]+1;
            second = i+1;
            return {first , second};
           }
            mp[numbers[i]] = i;
        }
        return {};
    }
};