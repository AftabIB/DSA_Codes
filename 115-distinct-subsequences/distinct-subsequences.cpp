class Solution {
public:
    //recursion(TLE)
    // int solve(int i,int j,string &s, string &t)
    // {
    //     //base case
    //     if(j < 0)
    //         return 1;
        
    //     if(i < 0)
    //         return 0;
        
    //     if(s[i] == t[j])
    //         return solve(i-1,j-1,s,t) + solve(i-1,j,s,t);
    //     else
    //         return solve(i-1,j,s,t);
    // }

    // int numDistinct(string s, string t) {
    //     int i = s.size();
    //     int j = t.size();
    //     return solve(i-1,j-1,s,t);
    // }

    //Memoization(TLE)
    // int solve(int i,int j,string &s, string &t,vector<vector<int>> &dp)
    // {
    //     //base case
    //     if(j < 0)
    //         return 1;
        
    //     if(i < 0)
    //         return 0;

    //     if(dp[i][j] != -1)
    //         return dp[i][j];
        
    //     if(s[i] == t[j])
    //         return solve(i-1,j-1,s,t,dp) + solve(i-1,j,s,t,dp);
    //     else
    //         return solve(i-1,j,s,t,dp);
    // }

    // int numDistinct(string s, string t) {
    //     int i = s.size();
    //     int j = t.size();
    //     vector<vector<int>> dp(i,vector<int>(j,-1));
    //     return solve(i-1,j-1,s,t,dp);
    // }

    //Tabulation
    double numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        
        for(int i=0;i<=n;i++)
            dp[i][0] = 1;
        
        for(int j=1;j<=m;j++)
            dp[0][j] = 0;
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1] == t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }

        }

        return dp[n][m];
    }

};