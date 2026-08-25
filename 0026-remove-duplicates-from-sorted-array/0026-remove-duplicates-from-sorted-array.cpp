class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int i =0;
    int count=0;
   for(int j =1 ; j<n ; j++){
    while(j<n && nums[j-1] == nums[j]){
        j++;
    }
    i++;
    if(j<n){
    nums[i]=nums[j];
    count++;
    }
   }
    
  return count+1;
    }
};