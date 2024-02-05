/* https://leetcode.com/problems/longest-common-subsequence/description/ */
/* https://www.codingninjas.com/studio/problems/longest-common-substring_1235207 */
/* https://leetcode.com/problems/longest-palindromic-subsequence/description/ */
// TC - exponential, O(n1 * n2), sc = O(n2);
class Solution {
private:
    int lcs(int i, int j, string& text1, string& text2, vector<vector<int>>& dp) {
        if (i == 0 || j == 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (text1[i - 1] == text2[j - 1])
            return dp[i][j] = 1 + lcs(i - 1, j - 1, text1, text2, dp);
        else
            return dp[i][j] = max(lcs(i - 1, j, text1, text2, dp), lcs(i, j - 1, text1, text2, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        return lcs(n1, n2, text1, text2, dp);

        vector<int>prev (n2 + 1, 0), curr(n2 + 1, 0);
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (text1[i - 1] == text2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }

        return prev[n2];
    }

    // length of longest Palindromic subsequence
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return longestCommonSubsequence(s, t);
    }
};


// print LCS
string longestCommonSubsequence(string text1, string text2) {
    int n1 = text1.length();
    int n2 = text2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int i = n1, j = n2;
	string s = "";
	while (i > 0 && j > 0) {
		if (temp1[i - 1] == temp2[j - 1]) {
			s = s1[i - 1] + s;
			i--;
			j--;
		} else {
			if (dp[i - 1][j] > dp[i][j - 1])
				i--;
			else
				j--;
		}
	}
	return s;
}

// Longest common substring length
int lcs(string &str1, string &str2){
    // Write your code here.
    int n1 = str1.length();
    int n2 = str2.length();
    int res = INT_MIN;
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    // we can space optimize using prev and curr vectors
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0;   // we only want consecutive therefore put 0

            res = max(res, dp[i][j]);
        }
    }

    return res;
}