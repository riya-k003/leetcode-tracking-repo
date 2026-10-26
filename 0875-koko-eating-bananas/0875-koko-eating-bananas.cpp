class Solution {
public:
bool isvalid(int mid , vector<int>& arr , int h){
    int n = arr.size();
    long long hrscnt =0;

    for(int i =0 ; i<n ; i++){
        hrscnt += (arr[i]+mid-1)/mid;
    }
    return hrscnt<=h;
     
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n= piles.size();
        int s =1;
        int e = *max_element(piles.begin() , piles.end());
        int result = INT_MAX;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(isvalid(mid , piles , h)){
                result = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return result;
    }
};