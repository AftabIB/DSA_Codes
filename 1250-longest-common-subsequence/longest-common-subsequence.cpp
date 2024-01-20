class Solution {
public:
    //Recursion
    // int solve(int i, int j,string &text1, string &text2)
    // {
    //     //base case 
    //     if(i < 0 || j < 0)
    //         return 0;
        
    //     //matching case
    //     if(text1[i] == text2[j])
    //         return 1 + solve(i-1,j-1,text1,text2);
        
    //     //no matching case 
    //     return max(solve(i-1,j,text1,text2),solve(i,j-1,text1,text2));
    // }
    // int longestCommonSubsequence(string text1, string text2) {
    //     int i = text1.size();
    //     int j = text2.size();
    //     return solve(i-1,j-1,text1,text2);
    // }

    // memoization
    // int solve(int i, int j,string &text1, string &text2,vector<vector<int>> &dp)
    // {
    //     //base case 
    //     if(i < 0 || j < 0)
    //         return 0;

    //     if(dp[i][j] != -1)
    //         return dp[i][j];
        
    //     //matching case
    //     if(text1[i] == text2[j])
    //         return dp[i][j] = 1 + solve(i-1,j-1,text1,text2,dp);
        
    //     //no matching case 
    //     return dp[i][j] = max(solve(i-1,j,text1,text2,dp),solve(i,j-1,text1,text2,dp));
    // }
    // int longestCommonSubsequence(string text1, string text2) {
    //     int i = text1.size();
    //     int j = text2.size();
    //     vector<vector<int>> dp(i,vector<int>(j,-1));
    //     return solve(i-1,j-1,text1,text2,dp);
    // }

    //Tabulation
    // int longestCommonSubsequence(string text1, string text2) {
    //     int n = text1.size();
    //     int m = text2.size();
    //     // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    //     vector<int> prev(m+1,0),curr(n+1,0);
        
    //     //base case 
    //     for(int i=0;i<n;i++)
    //         dp[i][0] = 0;

    //     for(int j=0;j<m;j++)
    //         dp[0][j] = 0;

    //     for(int i=1;i<=n;i++)
    //     {
    //         for(int j=1;j<=m;j++)
    //         {
    //             if(text1[i-1] == text2[j-1])
    //                 dp[i][j] = 1 + dp[i-1][j-1];
    //             else
    //                 dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    //         }
    //     }
    //     return dp[n][m];
    // }

    //Space optimization
    int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    // Base case
    for (int i = 0; i <= m; i++)
        prev[i] = 0;

    for (int i = 1; i <= n; i++) {
        curr[0] = 0;
        for (int j = 1; j <= m; j++) {
            if (text1[i - 1] == text2[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        swap(prev, curr);  
    }
    return prev[m];
}

};