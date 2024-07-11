//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        unordered_map<int, int> area; // to store area of each component
        int componentId = 2; // to avoid conflict with 1 and 0 in the grid
        
        // Helper function for DFS
        function<int(int, int, int)> dfs = [&](int x, int y, int id) -> int {
            if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != 1 || visited[x][y]) return 0;
            visited[x][y] = true;
            grid[x][y] = id; // mark this cell with the component id
            int size = 1;
            size += dfs(x + 1, y, id);
            size += dfs(x - 1, y, id);
            size += dfs(x, y + 1, id);
            size += dfs(x, y - 1, id);
            return size;
        };
        
        // Find all components and their areas
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int areaSize = dfs(i, j, componentId);
                    area[componentId] = areaSize;
                    componentId++;
                }
            }
        }
        
        // If there's no 1 in the grid
        if (area.empty()) return 1;
        
        int maxArea = 0;
        for (const auto& a : area) {
            maxArea = max(maxArea, a.second);
        }
        
        // Try changing each 0 to 1 and see the effect
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighbors;
                    if (i > 0 && grid[i-1][j] > 1) neighbors.insert(grid[i-1][j]);
                    if (i < n-1 && grid[i+1][j] > 1) neighbors.insert(grid[i+1][j]);
                    if (j > 0 && grid[i][j-1] > 1) neighbors.insert(grid[i][j-1]);
                    if (j < m-1 && grid[i][j+1] > 1) neighbors.insert(grid[i][j+1]);
                    
                    int newArea = 1; // the cell itself
                    for (int id : neighbors) {
                        newArea += area[id];
                    }
                    maxArea = max(maxArea, newArea);
                }
            }
        }
        
        return maxArea;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends