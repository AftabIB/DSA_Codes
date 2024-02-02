//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int solve(int index,int buy,vector<long long> &prices,vector<vector<long long>> &dp)
    {
        //base case
        if(index == prices.size())
            return 0;
        
        if(dp[index][buy] != -1)
            return dp[index][buy];
        //take and not take conditions for both buy and sell
        // for buying
        long profit = 0;
        if(buy)     //for buying
        {
            int take = -prices[index] + solve(index+1,0,prices,dp);
            int notake = solve(index+1,1,prices,dp);
            profit = max(take,notake); 
        }
        else        //for selling
        {
            int take = prices[index] + solve(index+1,1,prices,dp);
            int notake = solve(index+1,0,prices,dp);
            profit = max(take,notake); 
        }

        return dp[index][buy] = profit;

    }
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        vector<vector<long long>> dp(n,vector<long long>(2,-1));
        return solve(0,1,prices,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends