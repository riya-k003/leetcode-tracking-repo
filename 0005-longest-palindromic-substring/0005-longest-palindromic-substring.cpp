class Solution {
public:

void expandcenter(const string &s , int left , int right , int& start , int& max_len){
    while(left >=0 && right<s.size() && s[left] == s[right]){
        int len = right-left+1;
        if(len > max_len){
            max_len = len;
            start = left;
        }
        left--;
        right++;
    }
}
    string longestPalindrome(string s) {
        int n = s.size();
        if(s.empty())return "";
        int max_len =1;
        int start =0;
        for(int i =0 ; i<n ; i++){
                expandcenter(s ,i , i , start , max_len);
                expandcenter(s , i , i+1 , start , max_len);
        }
        return s.substr(start , max_len);
        
    }
};