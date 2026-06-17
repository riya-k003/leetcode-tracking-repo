class Solution {
public:
vector<int>generateRows(vector<int>prev){
    vector<int>curr;
    curr.push_back(1);
    for(int i =1 ; i<prev.size() ; i++){
        int mid = prev[i-1]+prev[i];
        curr.push_back(mid);
    }
    curr.push_back(1);
    return curr;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>triangle;
        if(numRows == 0)return triangle;
        
        triangle.push_back({1});
        for(int i =1  ; i<numRows ; i++){
            triangle.push_back(generateRows(triangle.back()));
        }
        return triangle;
        
    }
};