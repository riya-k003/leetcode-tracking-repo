class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int maxi = 0;
        while(l<r){
            if(height[l] < height[r]){
                int water = height[l]*(r-l);
                maxi = max(maxi ,water);
                l++;
            }
            else if(height[l] > height[r]){
                int water = height[r]*(r-l);
                maxi = max(maxi , water);
                r--;
            }
            else{
                int water = height[r]*(r-l);
                maxi = max(maxi , water);
                l++;
                r--;
            }
        }
        return maxi;
    }
};