//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[]) {
    vector<vector<int>> dp(N, vector<int>(N, 0));

    // l is chain length
    for (int l = 2; l < N; l++) 
    { // l is the chain length.
        for (int i = 1; i < N - l + 1; i++) 
        {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) 
            {
                // cost = cost/scalar multiplications
                int q = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }

    return dp[1][N - 1];
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends