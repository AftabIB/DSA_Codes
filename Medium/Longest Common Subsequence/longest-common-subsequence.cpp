//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Recursion
    //Function to find the length of longest common subsequence in two strings.
    // int solve(int index1,int index2,string &s1,string &s2)
    // {
    //     //base case 
    //     if(index1 < 0 || index2 < 0)
    //         return 0;
        
    //     //matching case
    //     if(s1[index1] == s2[index2])
    //         return 1 + solve(index1-1,index2-1,s1,s2);
        
    //     return max(solve(index1-1,index2,s1,s2),solve(index1,index2-1,s1,s2));
    // }
    // int lcs(int n, int m, string s1, string s2)
    // {
    //     return solve(n-1,m-1,s1,s2);
    //     // your code here
    // }
    
    //Memoization
    int solve(int index1,int index2,string &s1,string &s2,vector<vector<int>> &dp)
    {
        //base case 
        if(index1 < 0 || index2 < 0)
            return 0;
        
        if(dp[index1][index2] != -1)
            return dp[index1][index2];
            
        //matching case
        if(s1[index1] == s2[index2])
            return  dp[index1][index2] = 1 + solve(index1-1,index2-1,s1,s2,dp);
        
        return dp[index1][index2] = max(solve(index1-1,index2,s1,s2,dp),solve(index1,index2-1,s1,s2,dp));
    }
    int lcs(int n, int m, string s1, string s2)
    {
        vector<vector<int>> dp(n,vector<int>(m+1,-1));
        return solve(n-1,m-1,s1,s2,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends