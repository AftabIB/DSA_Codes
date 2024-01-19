class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        for (int j = 0; j < m; j++) {
            dp[n - 1][j] = matrix[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                int up = dp[i + 1][j];
                int LD = (j > 0) ? dp[i + 1][j - 1] : up;
                int RD = (j < m - 1) ? dp[i + 1][j + 1] : up;

                dp[i][j] = matrix[i][j] + min(up, min(LD, RD));
            }
        }

        int minPathSum = INT_MAX;
        for (int j = 0; j < m; j++) {
            minPathSum = min(minPathSum, dp[0][j]);
        }

        return minPathSum;
    }
};
