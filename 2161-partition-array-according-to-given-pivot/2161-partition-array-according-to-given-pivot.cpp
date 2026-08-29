class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>less;
        vector<int>greater;
        vector<int>mid;
        for(int i =0 ; i<n ; i++){
            if(nums[i] < pivot){
                less.push_back(nums[i]);
            }
            else if(nums[i] > pivot){
                greater.push_back(nums[i]);
            }
            else if(nums[i] == pivot){
                mid.push_back(nums[i]);
            }
        }
        int i =0;
        while(i<less.size()){
            nums[i] = less[i];
            i++;
        }
        int j =0;
        while(j<mid.size()){
            nums[i] = mid[j];
            i++;
            j++;
        }
        int k=0;
        while(k<greater.size()){
            nums[i] = greater[k];
            i++;
            k++;
        }
       return nums;
    }
};