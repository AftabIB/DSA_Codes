class Solution {
public:
    //Recursion
    // int solve(int index,int buy,vector<int>& prices,int cap)
    // {
    //     //base case
    //     if(cap == 0)
    //         return 0;
    //     if(index == prices.size())
    //         return 0;
        
    //     //take and not take conditions for both buy and sell
    //     // for buying
    //     long profit = 0;
    //     if(buy)     //for buying
    //     {
    //         int take = -prices[index] + solve(index+1,0,prices,cap);
    //         int notake = solve(index+1,1,prices,cap);
    //         profit = max(take,notake); 
    //     }
    //     else        //for selling
    //     {
    //         int take = prices[index] + solve(index+1,1,prices,cap-1);
    //         int notake = solve(index+1,0,prices,cap);
    //         profit = max(take,notake); 
    //     }

    //     return profit;

    // }
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     return solve(0,1,prices,2);
    // }

    //Memoization
    int solve(int index, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>> &dp) {
    // base case
        if (cap == 0 || index == prices.size())
            return 0;

        if (dp[index][buy][cap] != -1)
            return dp[index][buy][cap];

        // take and not take conditions for both buy and sell
        long profit = 0;
        if (buy) {  // for buying
            int take = -prices[index] + solve(index + 1, 0, cap, prices, dp);
            int notake = solve(index + 1, 1, cap, prices, dp);
            profit = max(take, notake);
        } else {    // for selling
            int take = prices[index] + solve(index + 1, 1, cap - 1, prices, dp);
            int notake = solve(index + 1, 0, cap, prices, dp);
            profit = max(take, notake);
        }

        return dp[index][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cap = 2;  // assuming cap is 2 based on the original code
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(cap + 1, -1)));
        return solve(0, 1, cap, prices, dp);
    }
};