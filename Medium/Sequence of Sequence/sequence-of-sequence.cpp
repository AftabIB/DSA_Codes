//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int fun(int n, int m) {
        if(n==0) return 1;
        if(m==0) return 0;
        int ans=0;
        for(int i=m;i>= (1<<(n-1)) ; i--) {
            ans+= fun(n-1, i/2);
        }
        return ans;
    }
    int numberSequence(int m, int n){
        if(n>7 || (1<<(n-1)) > m) return 0;
        return fun(n,m);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends