//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int solve(int n, int k,vector<int> &cost ,vector<vector<int>> &dp)
    {
        if(n>=cost.size())
            return 0;
        
        if(dp[n][k] != -1)
            return dp[n][k];
            
        int noTake = solve(n+1,k,cost,dp);
        int take = 0;
        if(k >= cost[n])
        {
            int cashback = floor((9.0 / 10) * cost[n]);
            take = 1+solve(n+1,k-(cost[n]-cashback),cost,dp);
        }
        
        return dp[n][k] = max(take,noTake);
        
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<vector<int>> dp(n,vector<int>(total+1,-1));
        return solve(0,total,cost,dp);
        //Code Here
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
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends