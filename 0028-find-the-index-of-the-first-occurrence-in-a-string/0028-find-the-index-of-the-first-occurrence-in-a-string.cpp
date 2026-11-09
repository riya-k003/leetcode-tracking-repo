class Solution {
public:
    int strStr(string haystack, string needle) {
        int i =0 , j =0;
        int n = haystack.size();
        int m = needle.size();
        int first =0;
        while(i<= n-m){
            int j =0;
                while(j<m && haystack[i+j] == needle[j]){
                    j++;
                }
                if(j==m)return i;
               i++;
            }
        return -1;
    }
};