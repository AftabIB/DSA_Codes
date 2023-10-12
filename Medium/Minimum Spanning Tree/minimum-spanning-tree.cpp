//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,
        vector<pair<int,int>>, greater<pair<int,int>>> p;
        
        //visited vector for parent
        vector<int> vis(V,0);
        // if MST is asked then we can include the parent
        p.push({0,0});
        int sum = 0;
        while(!p.empty())
        {
            auto it = p.top();
            p.pop();
            //our node is second in MST list 
            int node = it.second;
            //our weight is first in MST list
            int wt = it.first;
            
            //if node already visited then continue
            if(vis[node] == 1)  continue;
            //if its not visited be the part of MST i.e. add it to the MST 
            vis[node] = 1;
            //add the weight to the sum
            sum += wt;
            // iterate to all the adjacent nodes
            for(auto j: adj[node])
            {
                //adjacent node
                int adjNode = j[0];
                //weight of edge
                int edgeWt = j[1];
                //if the adjacent node is not visited 
                    if(!vis[adjNode])
                    {
                        p.push({edgeWt,adjNode});
                    }
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends