//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    public:
void solve(int i,int n,vector<int>&ans,unordered_map<int,int>&mp,int prev)
{
    if(i==n)
    return ;
    int op1=prev-i;
    if(op1<0)
    {
        int op2=prev+i;
        mp[op2]++;
        ans.push_back(op2);
        prev=op2;
    }
    else if(mp.find(op1)==mp.end())
    {
        mp[op1]++;
        ans.push_back(op1);
        prev=op1;
    }
    else
    {
        ans.push_back(prev+i);
        mp[prev+i]++;
        prev=prev+i;
    }
    solve(i+1,n,ans,mp,prev);
}
    vector<int> recamanSequence(int n){
        // code here
        vector<int>ans;
        unordered_map<int,int>mp;
        ans.push_back(0);
        mp[0]++;
        solve(1,n,ans,mp,0);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends