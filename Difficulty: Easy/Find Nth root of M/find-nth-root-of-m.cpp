//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int l=1;
        int r=m;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(pow(mid,n) == m)
            {
                return mid;
            }
        
            if(pow(mid,n)>m)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
	        }
        }
        return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends