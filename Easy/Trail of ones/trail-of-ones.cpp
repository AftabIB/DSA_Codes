//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int mod =1e9 +7;
    int numberOfConsecutiveOnes(int n) {
        vector<vector<vector<int>>> dp(n +1,vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(n, 0, 0,dp);
    }
    
    int solve(int n, int twones, int flag,vector<vector<vector<int>>> &dp) {
        if (n == 0) {
            return flag ? 1 : 0;
        }
        if(dp[n][twones][flag] !=-1){
            return dp[n][twones][flag];
        }
        int take = 0, skip = 0;
        
        // Take 1
        if (twones) {
            take = solve(n - 1, 1, 1,dp);
        } else {
            take = solve(n - 1, 1, flag,dp);
        }
    
        // Take 0
        skip = solve(n - 1, 0, flag,dp);
    
        return dp[n][twones][flag] = (take + skip)%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends