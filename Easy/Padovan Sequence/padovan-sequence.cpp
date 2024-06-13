//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int padovanSequence(int n)
    {
        int mod = 1e9+7;
       //code here
        int p0 = 1,p1 = 1,p2 = 1,p = 0;         
        
        if(n<=2)
        {
            return 1;
        }
        
        for(int i=3;i<=n;i++)
        {
            p = (p0 + p1) % mod;
            p0 = p1;
            p1 = p2;
            p2 = p;
        }
        return p;
    }
    
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends