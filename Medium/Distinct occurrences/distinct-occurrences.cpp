//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    // Memoization(TLE)
    // int solve(int i,int j,string &S, string &T,vector<vector<int>> &dp)
    // {
    //     //base case
    //     if(j < 0)
    //         return 1;
    //     if(i < 0)
    //         return 0;
            
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
                    
    //     if(S[i] == T[j])
    //         return solve(i-1,j-1,S,T,dp) + solve(i-1,j,S,T,dp);
    //     else
    //         return solve(i-1,j,S,T,dp);
    // }
    // int subsequenceCount(string S, string T)
    // {
    //     int i = S.size();
    //     int j = T.size();
    //     vector<vector<int>> dp(i,vector<int> (j,-1));
    //     return solve(i-1,j-1,S,T,dp);
    //     //Your code here
    // }
    
    // Tabulation
    int subsequenceCount(string S, string T)
    {
        int mod = 1e9 + 7;
        int n = S.size();
        int m = T.size();
        
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        
        for(int i=0;i<=n;i++)
            dp[i][0] = 1;
        
        for(int j=1;j<=m;j++)
            dp[0][j] = 0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(S[i-1] == T[j-1])
                {
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod; 
                }
                else
                {
                    dp[i][j] = dp[i-1][j] % mod;
                }
            }
        }
        
        return dp[n][m]  % mod;
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends