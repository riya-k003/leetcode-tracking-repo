class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin() , tokens.end());
        int i =0 , j= tokens.size()-1;
        int score =0;
        int max_score =0;
        while(i<=j){
            if(tokens[i]<=power){
                score++;
                power -= tokens[i];
                i++;
                 max_score = max(score , max_score);
            }
            else if( score >0){
                score--;
                power+=tokens[j];
                j--;
            }
            else{
                break;
                }
           
        }
        return max_score;
    }
};