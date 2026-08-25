class Solution {
public:
    int maxArea(vector<int>& height) {
        int l =0;
        int r = height.size()-1;
        int min_height = INT_MAX;
        int max_water = INT_MIN;
        while(l<r){
            min_height = min(height[l] , height[r]);
            max_water = max(max_water , min_height*(r-l));
            if(height[l] < height[r]){
                l++;
            }
            else if(height[r]< height[l]){
                r--;
            }
            else{
                l++;
                r--;
            }
        }
        return max_water;
    }
};