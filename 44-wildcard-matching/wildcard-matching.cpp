class Solution {
public:
    bool solve(int i, int j, string& s, string& p,vector<vector<int>> &dp) {
        // Base cases
        if (j < 0) {
            // If pattern is exhausted, check if remaining characters in string are '*'
            for (int a = 0; a <= i; ++a) {
                if (s[a] != '*') {
                    return false;
                }
            }
            return true;
        }

        if (i < 0) {
            // If string is exhausted, check if remaining characters in pattern are '*'
            for (int b = 0; b <= j; ++b) {
                if (p[b] != '*') {
                    return false;
                }
            }
            return true;
        }

        if(dp[i][j] != -1)
            return dp[i][j];
            
        // Recursive cases
        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(i - 1, j - 1, s, p,dp);
        }

        if (p[j] == '*') {
            // Two possibilities: '*' matches one character in string or '*' matches zero characters
            return dp[i][j] = solve(i - 1, j, s, p,dp) || solve(i, j - 1, s, p,dp);
        }

        return false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return solve(n - 1, m - 1, s, p,dp);
    }
};
