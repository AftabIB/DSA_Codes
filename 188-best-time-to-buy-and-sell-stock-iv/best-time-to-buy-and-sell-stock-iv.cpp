//Memoization previous method

// class Solution {
// public:
// int solve(int index, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>> &dp) {
//     // base case
//         if (cap == 0 || index == prices.size())
//             return 0;

//         if (dp[index][buy][cap] != -1)
//             return dp[index][buy][cap];

//         long profit = 0;
//         if (buy) {  // for buying
//             int take = -prices[index] + solve(index + 1, 0, cap, prices, dp);
//             int notake = solve(index + 1, 1, cap, prices, dp);
//             profit = max(take, notake);
//         } else {    // for selling
//             int take = prices[index] + solve(index + 1, 1, cap - 1, prices, dp);
//             int notake = solve(index + 1, 0, cap, prices, dp);
//             profit = max(take, notake);
//         }

//         return dp[index][buy][cap] = profit;
//     }
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
//         return solve(0, 1, k, prices, dp);
//     }
// };



class Solution {
public:
        int solve(int index, int transNo, vector<int>& prices, int n, int k, vector<vector<int>>& dp) {
        // base case
        if (index == n || transNo == 2 * k)
            return 0;

        if (dp[index][transNo] != -1)
            return dp[index][transNo];

        if (transNo % 2 == 0) {
            // for buying
            return dp[index][transNo] = max(-prices[index] + solve(index + 1, transNo + 1, prices, n, k, dp), solve(index + 1, transNo, prices, n, k, dp));
        }

        return dp[index][transNo] = max(prices[index] + solve(index + 1, transNo + 1, prices, n, k, dp), solve(index + 1, transNo, prices, n, k, dp));
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 * k, -1));
        return solve(0, 0, prices, n, k, dp);
    }

};