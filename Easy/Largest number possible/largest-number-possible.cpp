//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        if(S>(9*N) ){
            return "-1";
        }
        if(S==0 && N>1){
            return "-1";
        }
        string v;
        int d,r;
        d=S/9;
        r=S%9;
        while(v.size()!=d){
            v.push_back('9');
        }
        if(v.size()<N){
            v.push_back(r+48);
        }
        while(v.size()!=N){
            v.push_back('0');
        }
       return v; 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends