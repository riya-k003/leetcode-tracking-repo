class Solution {
public:
    bool checkValidString(string s) {
        int minc=0 , maxc=0;
        for(auto & ch : s){
            if(ch == '('){
                minc++;
                maxc++;
            }
            else if(ch == ')'){
                minc--;
                maxc--;
            }
            else{
                minc--;
                maxc++;
            }
            if(minc < 0 )minc=0;
            if(maxc < 0) return false;
        }
        return (minc==0);
    }
};