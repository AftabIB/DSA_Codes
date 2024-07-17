//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto j : adj[i]) {
                indegree[j]++;
            }
        }
    
        // Step 2: Initialize the queue with all vertices having in-degree 0
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
    
        int cnt = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
    
            // Step 3: Reduce in-degree of all adjacent vertices
            for (auto i : adj[node]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
    
        // Step 4: Check if all vertices were included in the topological sort
        if (cnt == V) {
            return false; // No cycle
        }
    
        return true; // Cycle detected
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends