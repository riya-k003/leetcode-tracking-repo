class Solution {
public:
    unordered_map<char , string>mp{
        {'2',"abc"},{'3',"def"}, {'4',"ghi"} , {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
    };
    void comb(string& res , int i , string digits ,vector<string>& ans){
        if(i==digits.size()){
            ans.push_back(res);
            return;
        }
        string st = mp[digits[i]];
        for(auto& ch: st){
            res.push_back(ch);
            comb(res , i+1 , digits , ans);
            res.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string res ="";
        comb(res , 0 , digits , ans);
        return ans;
    }
};