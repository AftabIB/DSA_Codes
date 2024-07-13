//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    int solve(int index, int W, int *wt, int *val,vector<vector<int>> &dp)
    {
        //base case : only one element with sufficient weight and highest value
        if(index == 0)
        {
            if(wt[index] <= W)
            {
                return val[0];
            }
            else
            {
                return 0;
            }
        }        
    
        if(dp[index][W] != -1)
            return dp[index][W];
        
        int noTake = solve(index-1,W,wt,val,dp);
        int take = INT_MIN;
        if(wt[index] <= W)
        {
            take = val[index] + solve(index-1,W - wt[index], wt, val,dp);
        }
        
        return dp[index][W] = max(take,noTake);
        
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int> (W+1,-1));
       return solve(n-1,W,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends