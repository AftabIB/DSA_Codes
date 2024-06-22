//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafe(int x, int y,int n, vector<vector<int>> &m, vector<vector<int>> vis)
    {
        if((x >= 0 && x < n) && (y >= 0 && y < n) && vis[x][y] == 0 && m[x][y] == 1)
            return true;
        else
            return false;
    }
    
    void solve(int x, int y, vector<vector<int>> &m, int n, string path, vector<vector<int>> vis, vector<string> &ans)
    {
        //base case
        if(x == n-1 && y == n-1)
        {
            ans.push_back(path);
            return;
        }
        
        vis[x][y] = 1;
        
        //4 directions : D L R U
        
        // 1) Down
        int newx = x + 1;
        int newy = y;
        if(isSafe(newx,newy,n,m,vis))
        {
            path.push_back('D');
            solve(newx,newy,m,n,path,vis,ans);
            path.pop_back();
        }
        
        // 2) left
        newx = x;
        newy = y - 1;
        if(isSafe(newx,newy,n,m,vis))
        {
            path.push_back('L');
            solve(newx,newy,m,n,path,vis,ans);
            path.pop_back();
        }
        
        // 3) right
        newx = x;
        newy = y + 1;
        if(isSafe(newx,newy,n,m,vis))
        {
            path.push_back('R');
            solve(newx,newy,m,n,path,vis,ans);
            path.pop_back();
        }
        
        // 4) Up
        newx = x - 1;
        newy = y;
        if(isSafe(newx,newy,n,m,vis))
        {
            path.push_back('U');
            solve(newx,newy,m,n,path,vis,ans);
            path.pop_back();
        }
        
        vis[x][y] = 0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis = m;
        
        // if source is not reachable
        if(m[0][0] == 0)
            return ans;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                vis[i][j] = 0;
            }
        }
        
        string path = "";
        solve(0,0,m,n,path,vis,ans);
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
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends