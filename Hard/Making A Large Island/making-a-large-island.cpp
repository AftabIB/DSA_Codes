//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int maxIslandSize = 0;

        // Define directions for moving to adjacent cells: Up, Down, Left, and Right
        vector<int> dirX = {0, 0, -1, 1};
        vector<int> dirY = {-1, 1, 0, 0};

        // Helper function to perform DFS and count island size
        function<int(int, int, int)> dfs = [&](int x, int y, int color) {
            if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] != 1) return 0;

            grid[x][y] = color;
            int size = 1;

            for (int i = 0; i < 4; i++) {
                int newX = x + dirX[i];
                int newY = y + dirY[i];
                size += dfs(newX, newY, color);
            }

            return size;
        };

        // Step 1: Perform DFS to count sizes of each island and change their colors
        unordered_map<int, int> islandSizes; // Map color to island size
        int color = 2; // Starting from 2, as 0 and 1 are already used
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(i, j, color);
                    islandSizes[color] = size;
                    maxIslandSize = max(maxIslandSize, size);
                    color++;
                }
            }
        }

        // Step 2: Change each 0 to 1 and check its impact on island sizes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    set<int> adjacentColors;
                    int newSize = 1; // Count 1 for the current cell being changed

                    for (int k = 0; k < 4; k++) {
                        int newX = i + dirX[k];
                        int newY = j + dirY[k];

                        if (newX >= 0 && newX < n && newY >= 0 && newY < n) {
                            int color = grid[newX][newY];
                            if (color > 1 && adjacentColors.count(color) == 0) {
                                adjacentColors.insert(color);
                                newSize += islandSizes[color];
                            }
                        }
                    }

                    maxIslandSize = max(maxIslandSize, newSize);
                }
            }
        }

        return maxIslandSize;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends