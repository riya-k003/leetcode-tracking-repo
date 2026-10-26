class Solution {
public:
int getpivot(vector<int>&nums , int n){
    if (nums[0] <= nums[n - 1]) return 0;
    int s = 0;
    int e = n-1;
    while(s<e){
        int mid = s+(e-s)/2;
        if(nums[mid] >= nums[0]){
            s = mid+1;
        }
        else{
            e = mid;
        }
    }
    return s;
}

    int binarySearch(int s , int e , int target , vector<int>&nums){
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid] == target)return mid;
            else if(nums[mid] < target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = getpivot(nums , n);
      if(target >= nums[pivot] && nums[n-1] >= target){
        return binarySearch(pivot , n-1 , target , nums);
      }
      else{
        return binarySearch(0 , pivot-1 , target , nums);
      }
    }
};