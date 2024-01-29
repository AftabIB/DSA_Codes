//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/

    bool solve(int i, int j, string& str, string& pattern,vector<vector<int>> &dp) {
        // Base cases
        if (j < 0) {
            // If pattern is exhausted, check if remaining characters in string are '*'
            for (int a = 0; a <= i; ++a) {
                if (str[a] != '*') {
                    return false;
                }
            }
            return true;
        }

        if (i < 0) {
            // If string is exhausted, check if remaining characters in pattern are '*'
            for (int b = 0; b <= j; ++b) {
                if (pattern[b] != '*') {
                    return false;
                }
            }
            return true;
        }

        if(dp[i][j] != -1)
            return dp[i][j];
            
        // Recursive cases
        if (str[i] == pattern[j] || pattern[j] == '?') {
            return dp[i][j] = solve(i - 1, j - 1, str, pattern,dp);
        }

        if (pattern[j] == '*') {
            // Two possibilities: '*' matches one character in string or '*' matches zero characters
            return dp[i][j] = solve(i - 1, j, str, pattern,dp) || solve(i, j - 1, str, pattern,dp);
        }

        return false;
    }
    
    
    int wildCard(string pattern, string str) {
        int m = str.size();
        int n = pattern.size();
        
        // Initialize a 2D array for memoization
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    
        // Call the solve function with the memoization array
        return solve(m - 1, n - 1, str, pattern, dp);
    }

};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends