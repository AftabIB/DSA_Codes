//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int dfs(int n,vector<int>&dp){
            if(n <= 8) return n;
            if(dp[n] != -1) return dp[n];
            return dp[n] = max(n/2, dfs(n/2,dp)) + max(n/3, dfs(n/3,dp)) + max(n/4, dfs(n/4,dp));
        }
        int maxSum(int n)
        {
            //code here.
            vector<int> dp(n+1, -1);
            return dfs(n, dp);
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends