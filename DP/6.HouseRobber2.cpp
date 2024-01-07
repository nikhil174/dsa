/*  https://leetcode.com/problems/house-robber-ii/description/ */

class Solution {
private:
    int houseRobber2(vector<int>& nums, int start, int end) {
        int prev2 = 0;
        int prev = nums[start];

        for (int i = start + 1; i < end; i++) {
            int steel = nums[i] + prev2;
            int notSteel = prev;

            prev2 = prev;
            prev = max(steel, notSteel);
        }

        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        int withFirst = houseRobber2(nums, 0, n - 1);
        int noFirst = houseRobber2(nums, 1, n);

        return max(withFirst, noFirst);
    }
};