class Solution {
public:
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
    int solve(int i, int j,string &text1, string &text2,vector<vector<int>> &dp)
    {
        //base case 
        if(i < 0 || j < 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        //matching case
        if(text1[i] == text2[j])
            return dp[i][j] = 1 + solve(i-1,j-1,text1,text2,dp);
        
        //no matching case 
        return dp[i][j] = max(solve(i-1,j,text1,text2,dp),solve(i,j-1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i = text1.size();
        int j = text2.size();
        vector<vector<int>> dp(i,vector<int>(j,-1));
        return solve(i-1,j-1,text1,text2,dp);
    }
};