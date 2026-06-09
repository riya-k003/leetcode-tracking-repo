class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n =seats.size();
        int prev_person = -1;
        int max_dist=0;
        for(int i =0 ; i<n ; i++){
            if(seats[i] == 1){
                if(prev_person == -1){
                    max_dist = i;
                }else{
                    max_dist = max(max_dist , (i-prev_person)/2);
                }
                prev_person = i;
            }
        }
        max_dist = max(max_dist , (n-1)-prev_person);
        return max_dist;
    }
};