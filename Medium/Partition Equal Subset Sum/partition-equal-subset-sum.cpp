//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int index,int target,int *arr,vector<vector<int>> &dp)
    {
        if(target == 0)
            return 1;
        if(index == 0)
            return (arr[0] == target);
            
        if(dp[index][target] != -1) 
            return dp[index][target];
        
        int noTake = solve(index-1,target,arr,dp);
        int take = 0;
        if(target >= arr[index])
        {
            take = solve(index-1,target-arr[index],arr,dp);
        }
        
        return dp[index][target] = take || noTake; 
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int totalSum = 0;
        for(int i=0;i<N;i++)
            totalSum += arr[i];
        if(totalSum % 2)
            return false;
        int target = totalSum/2;
        vector<vector<int>> dp(N,vector<int>(target+1,-1));
        return solve(N-1,target,arr,dp);
        
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends