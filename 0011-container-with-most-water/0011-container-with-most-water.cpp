class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        while(l<r){
            mini = min(height[l], height[r]);
             maxi = max(maxi ,mini*(r-l));
            if(height[l] < height[r]){
                l++;
            }
            else if(height[l] > height[r]){
                r--;
            }
            else{
                l++;
                r--;
            }
        }
        return maxi;
    }
};