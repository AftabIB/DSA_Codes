//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    //Recursion
    
    // int solve(int index,int *price,int n)
    // {
    //     if(index == 0)
    //         return (n*price[0]);
        
    //     int noTake = 0 + solve(index-1,price,n);
    //     int take = INT_MIN;
    //     int rod_length = index + 1;
    //     if(rod_length <= n)
    //     {
    //         take = price[index] + solve(index,price,n-rod_length);
    //     }
        
    //     return max(noTake,take);
    // }
        
    // int cutRod(int price[], int n) {
    //     //code here
    //     return solve(n-1,price,n);
    // }
    
    //Memoization
    int solve(int index,int *price,int n,vector<vector<int>> &dp)
    {
        if(index == 0)
            return (n*price[0]);
        
        if(dp[index][n] != -1)
            return dp[index][n];
        
        int noTake = 0 + solve(index-1,price,n,dp);
        int take = INT_MIN;
        int rod_length = index + 1;
        if(rod_length <= n)
        {
            take = price[index] + solve(index,price,n-rod_length,dp);
        }
        
        return dp[index][n] = max(noTake,take);
    }
        
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(n-1,price,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends