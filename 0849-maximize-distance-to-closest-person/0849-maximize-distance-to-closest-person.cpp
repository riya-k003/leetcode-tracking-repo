class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int prev_person = -1;
        int max_dist = 0;

        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                if (prev_person == -1) {
                    // Case 1: Empty seats at the very beginning of the row
                    max_dist = i;
                } else {
                    // Case 2: Empty seats sitting between two people
                    max_dist = std::max(max_dist, (i - prev_person) / 2);
                }
                prev_person = i;
            }
        }

        // Case 3: Empty seats at the very end of the row
        max_dist = std::max(max_dist, (n - 1) - prev_person);

        return max_dist;
    }
};