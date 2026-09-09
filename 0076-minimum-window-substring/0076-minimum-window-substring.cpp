class Solution {
public:
bool check(unordered_map<char , int>&mps , unordered_map<char , int>& mpt){
    if(mpt.size() > mps.size())return false;
    for(auto & ch : mpt){
        if(mps.find(ch.first) == mps.end())return false;
        else{
            if(ch.second > mps[ch.first])return false;
        }
    }
    return true;
}
    string minWindow(string s, string t) {
        unordered_map<char , int>mpt;
        for(auto& ch: t){
            mpt[ch]++;
        }
        unordered_map<char , int>mps;
        int l =0;
        int r =0;
        int start = 0;
        int end =0;
        int mini = INT_MAX;
        while(r<s.size()){
            mps[s[r]]++;
            if(check(mps , mpt)){
                
                while(check(mps , mpt)){
                    int minimum = mini;
                    mini = min(r-l+1 , mini);
                    if(minimum != mini){
                        start =l;
                        end = r;
                    }
                    

                    mps[s[l]]--;
                    if(mps[s[l]] == 0){
                        mps.erase(s[l]);
                    }
                    l++;
                }
            }
            r++;
        }
        if(mini == INT_MAX)return "";
        return s.substr(start , end-start+1);
    }
};