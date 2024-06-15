//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long dp[26][26][26];
    long long solve(int cnt, int i, int j, int n)
    {
        if(cnt == n) return 1;
        if(dp[cnt][i][j] != -1) return dp[cnt][i][j];
        int dr[] = {0,0,-1,1};
        int dc[] = {-1,1,0,0};
        
        long long ans = 0;
        ans += solve(cnt+1, i, j, n);
        for(int ind = 0; ind < 4; ind++)
        {
            int newi = i + dr[ind];
            int newj = j + dc[ind];
            if(newi <= 4 && newi >= 1 && newj <= 3 && newj >= 1 &&
            !(newi == 4 && newj == 1) && !(newi == 4 && newj == 3))
            {
                ans += solve(cnt + 1, newi, newj, n);
            }
        }
        
        return dp[cnt][i][j] = ans;
    }
    long long getCount(int n) {
        memset(dp,-1,sizeof(dp));
        long long ans = 0;
        for(int i=1; i<=4; i++)
        {
            for(int j=1; j<=3; j++)
            {
                if(i == 4 && j == 1) continue;
                if(i == 4 && j == 3) continue;
                ans += solve(1,i,j, n);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends