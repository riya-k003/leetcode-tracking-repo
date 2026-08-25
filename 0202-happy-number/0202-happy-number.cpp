class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>st;
        while(n != 1){
        double num =n;
            if(num/10 > 0){
        int number =0;
                while(n){
                int digit = n%10;
                number += (digit * digit);
                n /= 10;
                }
                n = number;
                 if(st.find(n) != st.end()){
                        return false;
                 }
            st.insert(number);
            }
            else{
                return false;
            } 
        }
        return true;
    }
};