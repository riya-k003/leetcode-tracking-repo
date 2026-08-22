class Solution {
public:
bool isPalindrome(const string & s , int l , int r){
    while(l<r){
        if(s[l] != s[r])return false;
    l++;
    r--;
    }
    return true;
}
    bool validPalindrome(string s) {
        int cnt =0;
        int i =0;
        int j = s.size()-1;
        while(i<=j){
            if(s[i] == s[j]){
               
                i++;
                j--;
            }
            else{
                return isPalindrome(s , i+1 , j) || isPalindrome(s , i , j-1);
            }
        }
       return true;
        
    }
};