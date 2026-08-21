class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin() , tokens.end());
        int i =0 , j= tokens.size()-1;
        int score =0;
        int max_score =0;
        if(tokens.size() == 0)return 0;
        if(tokens[0] > power && score==0)return 0;
        while(i<=j){
            if(tokens[i]<=power){
                score++;
                power -= tokens[i];
                i++;
            }
            else if(tokens[j] <= power){
                score++;
                power-=tokens[j];
                j--;
            }
            else if( score >=1){
                int max_token = max(tokens[i] , tokens[j]);
                score--;
                power+=max_token;
                if(max_token == tokens[i])i++;
                else j--;
            }
            max_score = max(score , max_score);
        }
        return max_score;
    }
};