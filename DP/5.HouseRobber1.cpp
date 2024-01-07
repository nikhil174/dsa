/** https://leetcode.com/problems/house-robber/description/ */

class Solution {
private:
    int houseRobber(int i, vector<int>& nums, vector<int>& dp) {
        if (i == 0)
            return nums[i];

        if (i < 0)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int steel = nums[i] + houseRobber(i - 2, nums, dp);
        int notSteel = houseRobber(i - 1, nums, dp);

        return dp[i] = max(steel, notSteel);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n, -1);
        // return houseRobber(n - 1, nums, dp);

        // dp[0] = nums[0];
        int prev2 = 0;
        int prev = nums[0];
        for (int i = 1; i < n; i++) {
            int steel = nums[i];
            if (i > 1)
                steel += prev2;
            int notSteel = prev;

            prev2 = prev;
            prev = max(steel, notSteel);
        }

        return prev;
    }
};