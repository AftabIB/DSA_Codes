//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int mod=1e9+7;
    int solve(int index, int k, vector<int> &arr, vector<vector<int>>& dp) {
       
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
    
        dp[index][k] = (np + p)%mod;
    
        return dp[index][k];
    }
	int perfectSum(vector<int> &arr, int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(n - 1, sum, arr, dp);
	}
	
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int total = 0;
        for(auto it: arr)
            total += it;
        if(total - d < 0 || (total - d) % 2)
            return false;
        return perfectSum(arr,n,(total - d)/2);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends