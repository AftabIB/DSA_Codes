//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	 int solve(string str,int index,int sum,vector<vector<int>>&dp){
        if(index==str.length())
        return 1;
        if(dp[index][sum]!=-1)
        return dp[index][sum];
        int currentsum=0;
        int ans=0;
        for(int i=index;i<str.length();i++)
        {
            currentsum+=str[i]-'0';
            if(currentsum>=sum)
            ans=ans+ solve(str,i+1,currentsum,dp);
        }
        return dp[index][sum]=ans;
        
    }
    int TotalCount(string str){
        int n=str.length();
        vector<vector<int>>dp(n,vector<int>(n*9,-1));
        return solve(str,0,0,dp);
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends