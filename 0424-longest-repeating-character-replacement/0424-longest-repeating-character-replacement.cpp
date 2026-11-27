class Solution {
public:

    int characterReplacement(string s, int k) {
        int n= s.size();
        int maxi =0;
       int st =0;
       int max_freq =0;
       vector<int>Freq(26 , 0);
       for(int e =0 ; e<n ; e++){
        Freq[s[e] - 'A']++;
       max_freq = max(max_freq , Freq[s[e] - 'A']);
       while((e-st+1) - max_freq > k){
        Freq[s[st] - 'A']--;
        st++;
       }
        maxi = max(e-st+1 , maxi);
        }
       
        return maxi;
    }
};