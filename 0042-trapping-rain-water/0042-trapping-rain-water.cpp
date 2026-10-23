class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int lm =0;
        int rm =0;
        int water =0;
        while(l<r){
            if(height[l]<=height[r]){
                if(lm < height[l]){
                    lm = height[l];
                }
                else{
                    water += lm-height[l];
                }
                l++;
            }
            else{
                if(rm < height[r]){
                    rm = height[r];
                }
                else{
                    water += rm-height[r];
                }
                r--;
            }
        }
        return water;
    }
};