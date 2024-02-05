/* https://leetcode.com/problems/find-a-peak-element-ii/description/*/

// TC - O(n log m), SC = O(1)
class Solution {
private:
    int getMaxEleIndex(vector<vector<int>>& mat, int col, int n) {
        int maxEleIdx = 0;

        for (int i = 1; i < n; i++) {
            if (mat[maxEleIdx][col] < mat[i][col])
                maxEleIdx = i;
        }

        return maxEleIdx;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = m - 1;
        while (low <= high) {
            int mid = (low + high) >> 1; // col
            int row = getMaxEleIndex(mat, mid, n);

            int left = (mid == 0) ? -1 : mat[row][mid - 1];
            int right = (mid == m - 1) ? -1 : mat[row][mid + 1];

            if (left < mat[row][mid] && right < mat[row][mid])
                return { row, mid};
            else if (left > mat[row][mid])
                high = mid - 1;
            else
                low = mid + 1;
        }

        return { -1, -1};
    }
};