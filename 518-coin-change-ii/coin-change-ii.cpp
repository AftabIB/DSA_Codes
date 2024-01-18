// class Solution {
// public:
//     int solve(int index,int target,vector<int>& coins)
//     {
//         //base case
//         if(index == 0)
//             return (target % coins[0] == 0);
//         int notake = solve(index-1,target,coins);
//         int take = 0;
//         if(coins[index] <= target)
//             take = solve(index,target-coins[index],coins);
        
//         return notake + take;
//     }
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         return solve(n-1,amount,coins);
//     }
// };

//Memoization
class Solution {
public:
    int solve(int index,int target,vector<int>& coins,vector<vector<int>> &dp )
    {
        //base case
        if(index == 0)
            return (target % coins[0] == 0);
        
        if(dp[index][target] != -1)
            return dp[index][target];

        int notake = solve(index-1,target,coins,dp);

        int take = 0;
        if(coins[index] <= target)
            take = solve(index,target-coins[index],coins,dp);
        
        return dp[index][target] = notake + take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};