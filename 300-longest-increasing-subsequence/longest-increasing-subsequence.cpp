//Memozation
// class Solution {
// public:
//     int solve(int index, int prevIndex,vector<int>& nums,vector<vector<int>> &dp)
//     {
//         //base case
//         if(index == nums.size())
//             return 0;

//         if(dp[index][prevIndex+1] != -1)
//             return dp[index][prevIndex+1];

//         int noTake = solve(index+1,prevIndex,nums,dp);
//         int take = 0;
//         if(prevIndex == -1 || nums[index] > nums[prevIndex])
//         {
//             take = 1 + solve(index+1,index,nums,dp); 
//         }

//         return dp[index][prevIndex+1] = max(take,noTake);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n,vector<int>(n+1,-1));
//         return solve(0,-1,nums,dp);
//     }
// };

//Tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int index = n-1; index >= 0; index--) {
            for(int prev = index-1; prev >= -1; prev--) {
                int noTake = dp[index+1][prev+1];
                int take = 0;
                if(prev == -1 || nums[index] > nums[prev]) {
                    take = 1 + dp[index+1][index+1];
                }
                dp[index][prev+1] = max(noTake, take);
            }
        }
        return dp[0][0];
    }
};
