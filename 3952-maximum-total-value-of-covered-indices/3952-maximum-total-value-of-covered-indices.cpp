class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        long long ans = 0;
        int n = nums.size();

        int i = 0;

        while (i < n && s[i] == '1') {
            ans += nums[i];
            i++;
        }

        while (i < n) {
            if (s[i] == '0') {
                long long sum = nums[i];
                int mn = nums[i];

                int j = i + 1;

                while (j < n && s[j] == '1') {
                    sum += nums[j];
                    mn = min(mn, nums[j]);
                    j++;
                }

                ans += (sum - mn);
                i = j;
            } else {
                i++;
            }
        }

        return ans;
    }
};