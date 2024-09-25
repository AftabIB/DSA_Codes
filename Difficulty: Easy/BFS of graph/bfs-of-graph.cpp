//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void solve(int node,vector<int> adj[], int vis[], vector<int> &ans)
    {
        vis[node] = 1;
        ans.push_back(node);
        
        queue<int> q;
        q.push(node);
        
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            
            for(auto adjNode : adj[temp])
            {
                if(!vis[adjNode])
                {
                    vis[adjNode] = 1;
                    q.push(adjNode);
                    ans.push_back(adjNode);
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        vector<int> ans;
        solve(0,adj,vis,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends