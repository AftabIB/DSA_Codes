//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
#define setBits(x) __builtin_popcountll(x)
	int is_bleak(int n)
	{
	    
    int sp = 1; 
    long cnt = 1;
        while(1) {
            cnt *= 2;
            if(n <= (cnt+sp-1)) break;
            sp++;
        } 
        for(int i=1; i<=setBits(cnt-1); ++i) {
            if(((n-i) + setBits(n-i)) == n)
                return 0;
        }
        return 1;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends