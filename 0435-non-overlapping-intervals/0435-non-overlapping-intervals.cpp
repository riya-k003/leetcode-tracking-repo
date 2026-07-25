class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        int last = intervals[0][1];
        int count =0;
        for(int i=1 ; i<intervals.size() ; i++){
            if(last > intervals[i][0]){
                last = min(last , intervals[i][1]);
                count++;
            }
            else if(last <= intervals[i][1]){
                last = intervals[i][1];
            }

        }
        return count;
    }
};