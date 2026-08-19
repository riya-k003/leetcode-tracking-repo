class Solution {
public:
    string reverseVowels(string s) {
        int l = 0;
        int r = s.size()-1;
        unordered_set<char>vowel ={'a','e','i','o','u'};
        while(l<r){
            if((vowel.find(tolower(s[l])) != vowel.end() )&&( vowel.find(tolower(s[r]))!= vowel.end())){
                swap(s[l], s[r]);
                l++;
                r--;
            }
         if(vowel.find(tolower(s[l])) == vowel.end()){
            l++;
            continue;
            }

           if(vowel.find(tolower(s[r])) == vowel.end()){
            r--;
            continue;
           }
        }
        return s;
    }
};