//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
        int totalSum = 0;
        
        for(int i=0;i<n;i++)
            totalSum += arr[i];
        int k = totalSum;
        
        vector<vector<bool>> dp(n,vector<bool>(k + 1,0));
        for(int i=0;i<n;i++)
            dp[i][0] = true;
        
        if(arr[0] <= k)
            dp[0][arr[0]] = true;
        
        for(int index=1;index<n;index++)
        {
            for(int target=1;target<=k;target++)
            {
                bool noTake = dp[index-1][target];
                bool take = false;
                if(target >= arr[index])
                {
                    take = dp[index-1][target-arr[index]];
                }
                dp[index][target] = take | noTake;
            }
        }

        int mini = 1e9;
        for(int i=0;i<=totalSum/2;i++)
        {
            if(dp[n-1][i] == true)
            {
                mini = min(mini, abs((totalSum - i) - i));

            }
        }
        return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends