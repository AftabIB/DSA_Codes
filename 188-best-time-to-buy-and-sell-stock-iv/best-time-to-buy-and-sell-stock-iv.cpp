class Solution {
public:
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
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // int cap = 2;  // assuming cap is 2 based on the original code
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solve(0, 1, k, prices, dp);
    }
};