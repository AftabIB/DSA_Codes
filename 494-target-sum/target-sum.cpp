class Solution {
public:
    int solve(int index, int k, vector<int>& arr, vector<vector<int>>& dp) {
    
        if (index < 0){
            if(k==0)
                return 1;
            return 0;
        }
        
        if (dp[index][k] != -1)
            return dp[index][k];

        int np = solve(index - 1, k, arr, dp);
        int p = 0;
        if (arr[index] <= k) {
            p = solve(index - 1, k - arr[index], arr, dp);
        }

        dp[index][k] = (np + p);

        return dp[index][k];
    }

    int findWays(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return solve(n - 1, k, arr, dp);
    }

    int countPartitions(int n, int d, vector<int> &arr) {
        int total = 0;
        for(auto &it: arr)
            total += it;
        
        if(total - d < 0 || (total - d) % 2 )
            return false;
        
        return findWays(arr,(total - d)/2);
    }
    int findTargetSumWays(vector<int>& arr, int target) {
        int n = arr.size();
        return countPartitions(n,target,arr);
    }
};