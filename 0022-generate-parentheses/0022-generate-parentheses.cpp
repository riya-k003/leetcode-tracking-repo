class Solution {
public:

    void generate(string& st , int i , int j, int n, vector<string>& ans){
        if(i==n && j==n){
            ans.push_back(st);
            return;
        }
        if(i<n){
            st.push_back('(');
            generate(st , i+1 , j , n , ans);
            st.pop_back();
        }
        if(j<i){
            st.push_back(')');
            generate(st , i , j+1 , n , ans);
            st.pop_back();
        }
       
    }
    vector<string> generateParenthesis(int n) {
        string st = "";
        vector<string>ans;
        generate(st , 0 ,0 , n , ans);
        return ans;
    }
};