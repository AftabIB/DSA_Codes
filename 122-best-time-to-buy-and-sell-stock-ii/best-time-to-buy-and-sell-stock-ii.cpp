class Solution {
public:
    //Recursion
    // int solve(int index,int buy,vector<int>& prices)
    // {
    //     //base case
    //     if(index == prices.size())
    //         return 0;
        
    //     //take and not take conditions for both buy and sell
    //     // for buying
    //     long profit = 0;
    //     if(buy)     //for buying
    //     {
    //         int take = -prices[index] + solve(index+1,0,prices);
    //         int notake = solve(index+1,1,prices);
    //         profit = max(take,notake); 
    //     }
    //     else        //for selling
    //     {
    //         int take = prices[index] + solve(index+1,1,prices);
    //         int notake = solve(index+1,0,prices);
    //         profit = max(take,notake); 
    //     }

    //     return profit;

    // }
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     return solve(0,1,prices);
    // }

    //Memoization
    // int solve(int index,int buy,vector<int>& prices,vector<vector<int>> &dp)
    // {
    //     //base case
    //     if(index == prices.size())
    //         return 0;
        
    //     if(dp[index][buy] != -1)
    //         return dp[index][buy];
    //     //take and not take conditions for both buy and sell
    //     // for buying
    //     long profit = 0;
    //     if(buy)     //for buying
    //     {
    //         int take = -prices[index] + solve(index+1,0,prices,dp);
    //         int notake = solve(index+1,1,prices,dp);
    //         profit = max(take,notake); 
    //     }
    //     else        //for selling
    //     {
    //         int take = prices[index] + solve(index+1,1,prices,dp);
    //         int notake = solve(index+1,0,prices,dp);
    //         profit = max(take,notake); 
    //     }

    //     return dp[index][buy] = profit;

    // }
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n,vector<int>(2,-1));
    //     return solve(0,1,prices,dp);
    // }

    //Tabulation
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        
        dp[n][0] = dp[n][1] = 0;
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                long profit = 0;
                if(buy)     //for buying
                {
                    int take = -prices[index] + dp[index+1][0];
                    int notake = dp[index+1][1];
                    profit = max(take,notake); 
                }
                else        //for selling
                {
                    int take = prices[index] + dp[index+1][1];
                    int notake = dp[index+1][0];
                    profit = max(take,notake); 
                }

                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }
};