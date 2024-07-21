//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

// 3 ways we can say graph is bipartite graph : 
/*
    1) if graph contains the cycle which have the EVEN no. of vertices(cycle length) is bipartite
    2) if a linear graph does not have cycle is bipartite
    3) if graph contains the cycle which have the ODD no. of vertices(cycle length) is not a bipartite 
*/
    bool checkB(int start, vector<int>adj[], int color[])
    {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto i : adj[node])
            {
                //if adjacent node is not yet colored, give opposite color of it
                if(color[i] == -1)
                {
                    color[i] = !color[node];
                    q.push(i);
                } 
                
                //if adjacent node has already colored the same, someone previously colored 
                else if(color[i] == color[node]) 
                {
                    return false;
                }
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	   int color[V];
	   for(int i=0;i<V;i++)
	       color[i] = -1;
	   
	   for(int i=0;i<V;i++)
	   {
	       if(color[i] == -1)
	       {
	           if(checkB(i,adj,color) == false)
	            return false;
	       }
	   }
	   return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends