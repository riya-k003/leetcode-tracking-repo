class Solution {
public:

bool check( unordered_map<int , int>&freqS , unordered_map<int , int>&freqT){
    if(freqS.size() < freqT.size())return false;
    for(auto& ch : freqT){
        if(freqS.find(ch.first) == freqS.end())return false;
        else{
            if(freqS[ch.first] < ch.second)return false;
        }
    }
    return true;
}
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        unordered_map<int , int>freqS;
        unordered_map<int, int>freqT;
        for(auto& ch : t){
            freqT[ch]++;
        }
        int l =0 , r =0;
        int start =0 , end =0;
        int mini = INT_MAX;
        while(r < n){
            freqS[s[r]]++;
            if(check(freqS,freqT)){
                while(check(freqS , freqT)){
                    int prev = mini;
                    mini = min(mini , r-l+1);
                    if(prev != mini){
                        start =l;
                        end = r;
                    }
                    freqS[s[l]]--;
                    if(freqS[s[l]] == 0){
                        freqS.erase(s[l]);
                    }
                    l++;
                }
            }
                r++;
        }
        if(mini == INT_MAX)return "";
        return s.substr(start , mini);
    }
};