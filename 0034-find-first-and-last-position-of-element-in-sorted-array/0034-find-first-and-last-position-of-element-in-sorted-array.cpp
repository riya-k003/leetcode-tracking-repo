class Solution {
public:
    int firstocc(vector<int>&nums , int t){
        int ans =-1;
        int s =0;
        int e = nums.size()-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid] == t){
                ans = mid;
                e=mid-1;
            }
            else if(nums[mid]<t){
                s= mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }

    int lastocc(vector<int>&nums , int t){
        int ans = -1;
        int s = 0;
        int e = nums.size()-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid] == t){
                ans = mid;
                s =mid+1;
            }
            else if(nums[mid]<t){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstocc(nums , target);
        int last = lastocc(nums , target);
        return {first , last};
        
    }
};