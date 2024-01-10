//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

    // int solve(int index,int arr,vector<int> &dp)
    // {
    //     //base case
    //     if(index == 0)
    //         return arr[index];
        
    //     if(index < 0)
    //         return 0;
        
    //     if(dp[index] != -1)
    //         return dp[index];
        
    //     int take = arr[index] + solve(index-2,arr,dp);
    //     int notake = 0 + solve(index - 1,arr,dp);
        
    //     return dp[index] = max(take,notake);
    // }
	
	int findMaxSum(int *arr, int n) {
	    if (n == 0) return 0;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = max(0, arr[0]);
        for (int i = 2; i <= n; ++i) {
            dp[i] = max(dp[i - 1], arr[i - 1] + dp[i - 2]);
        }
        return dp[n];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends