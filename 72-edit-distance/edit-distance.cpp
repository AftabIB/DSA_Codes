class Solution {
public:
    // int solve(int i,int j,string &s1, string &s2)
    // {
    //     //base case
    //     if(i<0)
    //         return j+1;
        
    //     if(j<0)
    //         return i+1;

    //     if(s1[i] == s2[j])
    //         return solve(i-1,j-1,s1,s2);
    //     else
    //         return 1 + min(solve(i,j-1,s1,s2),min(solve(i-1,j,s1,s2),solve(i-1,j-1,s1,s2)));
    // }
    // int minDistance(string s1, string s2) {
    //     int n = s1.size();
    //     int m = s2.size();

    //     return solve(n-1,m-1,s1,s2);

    // }

    //Memoization
    // int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    // {
    //     // base case
    //     if (i == 0)
    //         return j;

    //     if (j == 0)
    //         return i;

    //     if (dp[i][j] != -1)
    //         return dp[i][j];

    //     if (s1[i-1] == s2[j-1])
    //         return dp[i][j] = solve(i - 1, j - 1, s1, s2, dp);
    //     else
    //         return dp[i][j] = 1 + min(solve(i, j - 1, s1, s2, dp), min(solve(i - 1, j, s1, s2, dp), solve(i - 1, j - 1, s1, s2, dp)));
    // }

    // int minDistance(string s1, string s2)
    // {
    //     int n = s1.size();
    //     int m = s2.size();
    //     vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    //     return solve(n, m, s1, s2, dp);
    // }

    //Tabulation
    //  int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    // {
    //     // base case
    //     if (i == 0)
    //         return j;

    //     if (j == 0)
    //         return i;

    //     if (dp[i][j] != -1)
    //         return dp[i][j];

    //     if (s1[i-1] == s2[j-1])
    //         return dp[i][j] = solve(i - 1, j - 1, s1, s2, dp);
    //     else
    //         return dp[i][j] = 1 + min(solve(i, j - 1, s1, s2, dp), min(solve(i - 1, j, s1, s2, dp), solve(i - 1, j - 1, s1, s2, dp)));
    // }

    int minDistance(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    for (int i = 0; i <= n; i++)    
        dp[i][0] = i;
    
    for (int j = 0; j <= m; j++)    
        dp[0][j] = j;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            }
        }
    }
    return dp[n][m];
}

};