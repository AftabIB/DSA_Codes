//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(int i ,int j,string str)
    {
        // i = 0;
        // j = str.size()-1;
        
        while(i < j)
        {
            if(str[i] != str[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    int solve(int i, string str, int n,vector<int> &dp)
    {
        if(i == n)
            return 0;
        
        int mini = INT_MAX;
        
        if(dp[i] != -1)
            return dp[i];
            
        for(int index = i; index < n; index++)
        {
            // temp += str[index];
            if(isPalindrome(i,index,str))
            {
                int cost = 1 + solve(index+1,str,n,dp);
                mini = min(mini,cost);
            }
        }
        return dp[i] = mini;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        vector<int> dp(n,-1);
        return solve(0,str,n,dp) - 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends