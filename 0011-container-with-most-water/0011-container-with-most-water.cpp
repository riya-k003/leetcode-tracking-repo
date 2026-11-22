class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxi = 0;
        int s =0 , r=n-1;
        int water =0;
        while(s<r){
            if(height[s] <= height[r]){
                water = height[s] * (r-s);
                s++;
            }
            else if(height[s] > height[r]){
             water = height[r] * (r-s);
             r--;
            }
            maxi = max(water , maxi);
        }
        return maxi;
    }
};