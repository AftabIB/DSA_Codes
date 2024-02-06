class Solution {
public:
    // int solve(int i,int buy,vector<int>& prices)
    // {
    //     //base case 
    //     if(i >= prices.size())
    //         return 0;
        
    //     int profit = 0;
    //     if(buy)     //for buying
    //     {
    //         int take = -prices[i] + solve(i+1,0,prices);
    //         int notake = solve(i+1,1,prices);
    //         profit = max(take,notake);
    //     }
    //     else        //for selling
    //     {
    //         int sell = prices[i] + solve(i+2,1,prices);
    //         int nosell = solve(i+1,0,prices);
    //         profit = max(sell,nosell);
    //     }
    //     return profit;
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     return solve(0,1,prices);
    // }

    //memoizattion
    int solve(int i,int buy,vector<int>& prices,vector<vector<int>> &dp)
    {
        //base case 
        if(i >= prices.size())
            return 0;
        if(dp[i][buy] != -1)
            return dp[i][buy];

        int profit = 0;
        if(buy)     //for buying
        {
            int take = -prices[i] + solve(i+1,0,prices,dp);
            int notake = solve(i+1,1,prices,dp);
            profit = max(take,notake);
        }
        else        //for selling
        {
            int sell = prices[i] + solve(i+2,1,prices,dp);
            int nosell = solve(i+1,0,prices,dp);
            profit = max(sell,nosell);
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};